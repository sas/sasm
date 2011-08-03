#include "invalid.h"

namespace sasm { namespace instr { namespace mips {

invalid::invalid(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
}

void invalid::dump_asm(std::ostream& out) const
{
  out << "0x" << std::hex << _addr << std::dec << ": ";
  out << "invalid" << std::endl;
}

}}}
