#include "addu.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

addu::addu(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void addu::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "addu ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

}}}}