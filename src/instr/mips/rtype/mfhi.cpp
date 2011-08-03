#include "mfhi.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

mfhi::mfhi(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void mfhi::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "mfhi ";
  _dump_rd_reg(out);
  out << std::endl;
}

}}}}
