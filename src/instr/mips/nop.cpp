#include "nop.h"

namespace sasm { namespace instr { namespace mips {

nop::nop(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
}

void nop::dump_asm(std::ostream& out) const
{
  out << "0x" << std::hex << _addr << std::dec << ": ";
  out << "nop" << std::endl;
}

}}}
