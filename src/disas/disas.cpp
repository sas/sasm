#include "disas.h"

#include <elf/elf.h>

namespace sasm { namespace disas {

disas::disas(const sasm::elf::elf& elf)
  : _elf(elf), _current_addr(elf.get_entry())
{
}

}}
