#include "jr.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

jr::jr(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void jr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "jr ";
  _dump_rs_reg(out);
  out << std::endl;
}

}}}}
