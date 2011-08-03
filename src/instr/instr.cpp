#include "instr.h"

namespace sasm { namespace instr {

instr::instr(const sasm::elf::elf& elf, uint64 addr)
  : _elf(elf), _addr(addr)
{
}

}}
