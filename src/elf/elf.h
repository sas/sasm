#ifndef ELF_ELF_H_
# define ELF_ELF_H_

# include <elf/image.h>
# include <elf/symtab.h>
# include <elf/types.h>
# include <utils/mapped_file.h>

namespace sasm { namespace elf {

template<int word_size>
class elf
{
public:
  elf(sasm::utils::mapped_file& file);

  sasm::elf::image<word_size> image;
  sasm::elf::symtab<word_size> symtab;

  typedef typename sasm::elf::types<word_size>::addr addr_type;

  addr_type get_entry() const;

private:
  sasm::utils::mapped_file _file;

  typedef typename sasm::elf::types<word_size>::ehdr ehdr_type;
  ehdr_type _ehdr;
};

}}

# include "elf.hpp"
#endif /* !ELF_ELF_H_ */
