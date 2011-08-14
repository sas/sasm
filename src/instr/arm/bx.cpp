#include "bx.h"

#include <elf/elf.h>

#define ARM_BX_EXTRACT_RN(Instr)  (Instr & 0xf)

namespace sasm { namespace instr { namespace arm {

bx::bx(const sasm::elf::elf& elf, uint64 addr)
  : arm_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _rn_reg = ARM_BX_EXTRACT_RN(instr);
}

void bx::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "bx" << _get_cond() << " " << _get_reg_name(_rn_reg) << std::endl;
}

}}}
