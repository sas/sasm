#include "sll.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

sll::sll(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void sll::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "sll ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_sa_val(out);
  out << std::endl;
}

}}}}
