#include "add.h"

namespace sasm { namespace instr { namespace mips {

add::add(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
}

void add::dump_asm(std::ostream& out) const
{
  out << "0x" << std::hex << _addr << std::dec << ": ";
  out << "add $" << reg_d << ", $" << reg_s << ", $" << reg_t << std::endl;
}

}}}
