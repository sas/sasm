#include "j.h"

namespace sasm { namespace instr { namespace mips { namespace jtype {

j::j(const sasm::elf::elf& elf, uint64 addr)
  : jtype_instr(elf, addr)
{
}

void j::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "j ";
  _dump_target_val(out);
  out << std::endl;
}

}}}}
