#include "image.h"

#include <elf/info.h>
#include <elf/types.h>

namespace sasm { namespace elf {

template<int word_size>
static void read_segments(const sasm::utils::mapped_file& file, std::list<image::segment>& seg_list)
{
  typedef typename sasm::elf::types<word_size>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<word_size>::phdr  phdr_type;

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
}

image::image(const sasm::utils::mapped_file& file)
  : _file(file)
{
  int word_size = sasm::elf::get_class(file);

  if (word_size == 32)
    read_segments<32>(file, _segments);
  else if (word_size == 64)
    read_segments<64>(file, _segments);

  _segments.sort([](segment first, segment second){ return first.vaddr < second.vaddr; });
}

}}
