#include "symtab.h"

#include <pervasive.h>
#include <elf/elf.h>
#include <elf/types.h>

namespace sasm { namespace elf {

template<int elf_class>
static void read_symbols(
    const sasm::utils::mapped_file& file,
    std::map<std::string, std::shared_ptr<symtab::symbol>>& name_map,
    std::multimap<uint64, std::shared_ptr<symtab::symbol>>& addr_map
  )
{
  typedef typename sasm::elf::types<elf_class>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<elf_class>::shdr  shdr_type;
  typedef typename sasm::elf::types<elf_class>::sym   sym_type;

  auto ehdr = file.read<ehdr_type>(0);
  uint64 symtab_offset;
  int sym_count = -1;
  uint64 strtab_offset;

  for (int i = 0; i < ehdr.e_shnum; ++i)
  {
    auto shdr = file.read<shdr_type>(ehdr.e_shoff + i * sizeof (shdr_type));

    if (shdr.sh_type == SHT_SYMTAB)
    {
      symtab_offset = shdr.sh_offset;
      sym_count = shdr.sh_size / shdr.sh_entsize;

      shdr = file.read<shdr_type>(ehdr.e_shoff + shdr.sh_link * sizeof (shdr_type));
      strtab_offset = shdr.sh_offset;

      break;
    }
  }

  for (int i = 0; i < sym_count; ++i)
  {
    auto elf_sym = file.read<sym_type>(symtab_offset + i * sizeof (sym_type));
    auto sym = std::shared_ptr<symtab::symbol>(new symtab::symbol);

    /* We can use ELF32_ST_TYPE because it is the same macro for ELF64. */
    int type = ELF32_ST_TYPE(elf_sym.st_info);

    /* XXX: We should store every symbol here, not just these types. */
    if (type != STT_NOTYPE && type != STT_OBJECT && type != STT_FUNC && type != STT_COMMON)
      continue;

    /* Easy convertion between STT_* and enum class type. */
    static std::map<int, symtab::symbol::sym_type> stt_to_enum = {
      { STT_NOTYPE, symtab::symbol::sym_type::notype },
      { STT_OBJECT, symtab::symbol::sym_type::object },
      { STT_FUNC,   symtab::symbol::sym_type::func },
      { STT_COMMON, symtab::symbol::sym_type::common },
    };

    for (int j = 0, c; (c = file[strtab_offset + elf_sym.st_name + j]) != 0; ++j)
      sym->name.append(1, c);
    sym->addr = elf_sym.st_value;
    sym->size = elf_sym.st_size;
    sym->type = stt_to_enum[type];

    name_map.insert(std::pair<std::string, std::shared_ptr<symtab::symbol>>(sym->name, sym));
    addr_map.insert(std::pair<uint64, std::shared_ptr<symtab::symbol>>(sym->addr, sym));
  }
}

symtab::symtab(const sasm::utils::mapped_file& file)
{
  int elf_class = sasm::elf::elf::get_class(file);

  if (elf_class == ELFCLASS32)
    read_symbols<ELFCLASS32>(file, _name_map, _addr_map);
  else if (elf_class == ELFCLASS64)
    read_symbols<ELFCLASS64>(file, _name_map, _addr_map);
}

}}
