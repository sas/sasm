#include "info.h"

#include <pervasive.h>

#include <elf.h>

namespace sasm { namespace elf {

int get_class(const sasm::utils::mapped_file& file)
{
  const byte* begin = &file.read<byte>(0);

  if (begin[EI_CLASS] == ELFCLASS32)
    return 32;
  else if (begin[EI_CLASS] == ELFCLASS64)
    return 64;
  else
    return -1;
}

}}
