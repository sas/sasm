#include "elf.h"

namespace sasm { namespace elf {

elf::elf(sasm::utils::mapped_file& file)
  : image(file), symtab(file), _file(file)
{
}

}}
