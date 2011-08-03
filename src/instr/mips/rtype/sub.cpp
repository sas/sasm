#include "sub.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

sub::sub(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void sub::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "sub ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

}}}}
