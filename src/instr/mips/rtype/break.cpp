#include "break.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

break_::break_(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void break_::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "break";
  out << std::endl;
}

}}}}
