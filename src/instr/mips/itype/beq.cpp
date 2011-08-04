#include "beq.h"

namespace sasm { namespace instr { namespace mips { namespace itype {

beq::beq(const sasm::elf::elf& elf, uint64 addr)
  : itype_instr(elf, addr)
{
}

void beq::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "beq ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_immed_val(out, true);
  out << std::endl;
}

}}}}
