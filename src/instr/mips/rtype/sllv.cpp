#include "sllv.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

sllv::sllv(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void sllv::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "sllv ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << std::endl;
}

}}}}
