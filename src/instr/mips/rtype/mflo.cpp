#include "mflo.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

mflo::mflo(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void mflo::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "mflo ";
  _dump_rd_reg(out);
  out << std::endl;
}

}}}}
