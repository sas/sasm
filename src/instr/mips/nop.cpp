#include "nop.h"

namespace sasm { namespace instr { namespace mips {

nop::nop(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
}

void nop::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "nop";
  out << std::endl;
}

}}}
