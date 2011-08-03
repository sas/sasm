#include "jalr.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

jalr::jalr(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void jalr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "jalr ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << std::endl;
}

}}}}