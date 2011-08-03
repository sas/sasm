#include "sra.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

sra::sra(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void sra::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "sra ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_sa_val(out);
  out << std::endl;
}

}}}}
