#ifndef ELF_IMAGE_H_
# define ELF_IMAGE_H_

# include <elf/types.h>
# include <utils/mapped_file.h>

# include <list>

namespace sasm { namespace elf {

template<int word_size>
class image
{
public:
  typedef typename sasm::elf::types<word_size>::addr  addr_type;

private:
  typedef typename sasm::elf::types<word_size>::off   off_type;
  typedef typename sasm::elf::types<word_size>::word  word_type;

  struct segment
  {
    addr_type vaddr;
    addr_type paddr;
    off_type  offset;
    word_type mem_size;
    word_type file_size;
  };

public:
  image(sasm::utils::mapped_file& file);

  template<typename T> const T& read(addr_type addr) const;

private:
  sasm::utils::mapped_file& _file;
  std::list<segment> _segments;
};

}}

# include "image.hpp"
#endif /* !ELF_IMAGE_H_ */
