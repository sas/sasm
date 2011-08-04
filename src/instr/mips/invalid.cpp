#include "invalid.h"

namespace sasm { namespace instr { namespace mips {

invalid::invalid(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
}

void invalid::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "invalid" << std::endl;
}

}}}
