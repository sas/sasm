#ifndef ELF_ELF_HH_
# define ELF_ELF_HH_

# include <elf/symtab.h>
# include <utils/mapped_file.h>

namespace sasm { namespace elf {

template<int word_size>
class elf
{
public:
  elf(sasm::utils::mapped_file& file);

private:
  sasm::utils::mapped_file _file;
  sasm::elf::symtab<word_size> _symtab;
};

}}

# include "elf.hpp"
#endif /* !ELF_ELF_HH_ */
