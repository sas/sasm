#include <elf/elf.h>
#include <elf/types.h>

#include "sections.h"

namespace sasm { namespace elf {

template<int elf_class>
void read_sections(
    const sasm::utils::mapped_file& file,
    std::map<std::string, sections::section>& sections
  )
{
  typedef typename sasm::elf::types<elf_class>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<elf_class>::shdr  shdr_type;

  auto ehdr = file.read<ehdr_type>(0);
  auto shstr_hdr = file.read<shdr_type>(ehdr.e_shoff + ehdr.e_shstrndx * sizeof (shdr_type));
  uint64 shstr_offset = shstr_hdr.sh_offset;

  for (int i = 0; i < ehdr.e_shnum; ++i)
  {
    auto shdr = file.read<shdr_type>(ehdr.e_shoff + i * sizeof (shdr_type));
    sections::section sect;

    for (int j = 0, c; (c = file[shstr_offset + shdr.sh_name + j]) != 0; ++j)
      sect.name.append(1, c);
    sect.vaddr = shdr.sh_addr;
    sect.size = shdr.sh_size;
    sect.flags = shdr.sh_flags;

    sections[sect.name] = sect;
  }
}

sections::sections(const sasm::utils::mapped_file& file)
  : _file(file), _sections()
{
  int elf_class = sasm::elf::elf::get_class(file);

  if (elf_class == ELFCLASS32)
    read_sections<ELFCLASS32>(file, _sections);
  else if (elf_class == ELFCLASS64)
    read_sections<ELFCLASS64>(file, _sections);
}

}}
