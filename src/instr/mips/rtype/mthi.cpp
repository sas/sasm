#include "mthi.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

mthi::mthi(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void mthi::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "mthi ";
  _dump_rs_reg(out);
  out << std::endl;
}

}}}}
