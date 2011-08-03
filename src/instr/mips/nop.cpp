#include "nop.h"

namespace sasm { namespace instr { namespace mips {

nop::nop(const sasm::elf::elf& elf)
  : instr(elf)
{
}

void nop::dump_asm(std::ostream& out) const
{
  out << "nop" << std::endl;
}

}}}
