#include "info.h"

#include <pervasive.h>

#include <elf.h>

namespace sasm { namespace elf {

int get_class(const sasm::utils::mapped_file& file)
{
  const byte* begin = &file.read<byte>(0);
  return begin[EI_CLASS];
}

}}
