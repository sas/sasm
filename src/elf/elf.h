#ifndef ELF_ELF_H_
# define ELF_ELF_H_

# include <pervasive.h>
# include <elf/image.h>
# include <elf/symtab.h>
# include <elf/types.h>
# include <utils/mapped_file.h>

namespace sasm { namespace elf {

class elf
{
public:
  elf(sasm::utils::mapped_file& file);

  sasm::elf::image  image;
  sasm::elf::symtab symtab;

private:
  sasm::utils::mapped_file _file;
};

}}

# include "elf.hpp"
#endif /* !ELF_ELF_H_ */
