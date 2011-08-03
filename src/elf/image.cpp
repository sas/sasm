#include "image.h"

#include <elf/info.h>
#include <elf/types.h>

namespace sasm { namespace elf {

template<int elf_class>
static void read_segments(const sasm::utils::mapped_file& file, std::list<image::segment>& seg_list)
{
  typedef typename sasm::elf::types<elf_class>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<elf_class>::phdr  phdr_type;

  auto ehdr = file.read<ehdr_type>(0);

  for (int i = 0; i < ehdr.e_phnum; ++i)
  {
    auto phdr = file.read<phdr_type>(ehdr.e_phoff + i * sizeof (phdr_type));
    image::segment seg;

    seg.vaddr = phdr.p_vaddr;
    seg.paddr = phdr.p_paddr;
    seg.offset = phdr.p_offset;
    seg.mem_size = phdr.p_memsz;
    seg.file_size = phdr.p_filesz;

    seg_list.push_back(seg);
  }

  seg_list.sort([](image::segment first, image::segment second){ return first.vaddr < second.vaddr; });
}

image::image(const sasm::utils::mapped_file& file)
  : _file(file)
{
  int elf_class = sasm::elf::get_class(file);

  if (elf_class == ELFCLASS32)
    read_segments<ELFCLASS32>(file, _segments);
  else if (elf_class == ELFCLASS64)
    read_segments<ELFCLASS64>(file, _segments);
}

}}
