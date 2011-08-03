#include "divu.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

divu::divu(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void divu::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "divu ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

}}}}
