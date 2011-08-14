#include "branch.h"

#define ARM_BRANCH_EXTRACT_LINK(Instr)   (Instr & (1 << 24))
#define ARM_BRANCH_EXTRACT_OFFSET(Instr) (Instr & ((1 << 24) - 1))

namespace sasm { namespace instr { namespace arm {

branch::branch(const sasm::elf::elf& elf, uint64 addr)
  : arm_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _link = ARM_BRANCH_EXTRACT_LINK(instr);
  _offset = ARM_BRANCH_EXTRACT_OFFSET(instr);

  /* Sign extension. */
  if (_offset & (1 << 23))
    _offset |= 0xff << 24;

  _offset = (_offset << 2) + 8;
}

void branch::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "b" << (_link ? "l" : "") << _get_cond() << " "
    << _get_rela_addr(_offset) << std::endl;
}

}}}
