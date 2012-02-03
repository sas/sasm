#ifndef ELF_IMAGE_H_
# define ELF_IMAGE_H_

# include <list>

# include <utils/mapped_file.h>

namespace sasm { namespace elf {

class image
{
public:
  image(const sasm::utils::mapped_file& file);
  template<typename T> const T& read(uint64 addr) const;

private:
  struct segment
  {
    uint64 vaddr;
    uint64 paddr;
    uint64 offset;
    uint64 mem_size;
    uint64 file_size;
  };

  const sasm::utils::mapped_file& _file;
  std::list<segment>              _segments;
};

}}

# include "image.hpp"
#endif /* !ELF_IMAGE_H_ */
