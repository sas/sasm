#include "instr.h"

#define MIPS_JTYPE_EXTRACT_TARGET(Instr) (Instr & ((1 << 26) - 1))

namespace sasm { namespace instr { namespace mips { namespace jtype {

jtype_instr::jtype_instr(const sasm::elf::elf& elf, uint64 addr)
  : mips_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _target_val = MIPS_JTYPE_EXTRACT_TARGET(instr);
}

void jtype_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  uint32 dst_addr = (_target_val << 2) + ((_addr >> 28) << 28);
  out << _name << " " << _get_abs_addr(dst_addr) << std::endl;
}

}}}}
