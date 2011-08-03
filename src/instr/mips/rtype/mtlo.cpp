#include "mtlo.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

mtlo::mtlo(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void mtlo::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "mtlo ";
  _dump_rs_reg(out);
  out << std::endl;
}

}}}}