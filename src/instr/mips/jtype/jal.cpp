#include "jal.h"

namespace sasm { namespace instr { namespace mips { namespace jtype {

jal::jal(const sasm::elf::elf& elf, uint64 addr)
  : jtype_instr(elf, addr)
{
}

void jal::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "jal ";
  _dump_target_val(out);
  out << std::endl;
}

}}}}
