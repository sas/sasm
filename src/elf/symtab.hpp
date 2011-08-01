#include <stdexcept>

namespace sasm { namespace elf {

template<int word_size>
symtab<word_size>::symtab(const sasm::utils::mapped_file& file)
{
  typedef typename sasm::elf::types<word_size>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<word_size>::shdr  shdr_type;
  typedef typename sasm::elf::types<word_size>::sym   sym_type;

  auto ehdr = file.read<ehdr_type>(0);
  off_type symtab_offset;
  int sym_count = -1;
  off_type strtab_offset;

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
    auto sym = std::shared_ptr<symbol>(new symbol);

    for (int j = 0, c; (c = file[strtab_offset + elf_sym.st_name + j]) != 0; ++j)
      sym->name.append(1, c);
    sym->addr = elf_sym.st_value;
    sym->size = elf_sym.st_size;

    _name_map[sym->name] = sym;
    _addr_map[sym->addr] = sym;
  }
}

template<int word_size>
auto symtab<word_size>::get_sym(const std::string& name) const -> const symbol&
{
  auto res = _name_map.find(name);

  if (res != _name_map.end())
    return *res->second;
  else
    throw std::out_of_range("symtab::get_sym");
}

template<int word_size>
auto symtab<word_size>::get_sym(addr_type addr) const -> const symbol&
{
  auto res = _addr_map.find(addr);

  if (res != _addr_map.end())
    return *res->second;
  else
    throw std::out_of_range("symtab::get_sym");
}

template<int word_size>
auto symtab<word_size>::operator[](const std::string& name) const -> const symbol&
{
  return this->get_sym(name);
}

template<int word_size>
auto symtab<word_size>::operator[](addr_type addr) const -> const symbol&
{
  return this->get_sym(addr);
}

}}
