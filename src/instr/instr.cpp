#include "instr.h"

namespace sasm { namespace instr {

instr::instr(const sasm::elf::elf& elf)
  : _elf(elf)
{
}

}}
