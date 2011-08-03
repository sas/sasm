#include "mult.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

mult::mult(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void mult::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "mult ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

}}}}
