#include <stdexcept>

namespace sasm { namespace elf {

template<typename T>
const T& image::read(uint64 addr) const
{
  /* XXX: Does not support sections like .bss where mem_size > file_size. */
  for (auto i = _segments.begin(); i != _segments.end(); ++i)
    if (addr >= i->vaddr && addr < i->vaddr + i->mem_size)
      return _file.read<T>(i->offset + addr - i->vaddr);

  throw std::out_of_range("sasm::elf::image::read");
}

}}
