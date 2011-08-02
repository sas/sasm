#include <stdexcept>

namespace sasm { namespace elf {

template<int word_size>
image<word_size>::image(sasm::utils::mapped_file& file)
  : _file(file)
{
  typedef typename sasm::elf::types<word_size>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<word_size>::phdr  phdr_type;

  auto ehdr = file.read<ehdr_type>(0);

  for (int i = 0; i < ehdr.e_phnum; ++i)
  {
    auto phdr = file.read<phdr_type>(ehdr.e_phoff + i * sizeof (phdr_type));
    segment seg;

    seg.vaddr = phdr.p_vaddr;
    seg.paddr = phdr.p_paddr;
    seg.offset = phdr.p_offset;
    seg.mem_size = phdr.p_memsz;
    seg.file_size = phdr.p_filesz;

    _segments.push_back(seg);
  }

  _segments.sort([](segment first, segment second) { return first.vaddr < second.vaddr; });
}

template<int word_size>
template<typename T>
const T& image<word_size>::read(addr_type addr) const
{
  /* XXX: Does not support sections like .bss where mem_size > file_size. */
  for (auto i = _segments.begin(); i != _segments.end(); ++i)
    if (addr >= i->vaddr && addr < i->vaddr + i->mem_size)
      return _file.read<T>(i->offset + addr - i->vaddr);

  throw std::out_of_range("sasm::elf::image::read");
}

}}
