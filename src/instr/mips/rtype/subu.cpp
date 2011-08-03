#include "subu.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

subu::subu(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void subu::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "subu ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

}}}}
