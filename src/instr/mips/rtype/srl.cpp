#include "srl.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

srl::srl(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void srl::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "srl ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_sa_val(out);
  out << std::endl;
}

}}}}
