#include <utils/bitops.h>

#include "mult.h"

#define ARM_BRANCH_EXTRACT_LONG(Instr)        EXTRACT_BIT(Instr, 23)
#define ARM_BRANCH_EXTRACT_UNSIGNED(Instr)    EXTRACT_BIT(Instr, 22)
#define ARM_BRANCH_EXTRACT_ACCUMULATE(Instr)  EXTRACT_BIT(Instr, 21)
#define ARM_BRANCH_EXTRACT_SETCOND(Instr)     EXTRACT_BIT(Instr, 20)
#define ARM_BRANCH_EXTRACT_RD(Instr)          EXTRACT_BITRANGE(Instr, 19, 16)
#define ARM_BRANCH_EXTRACT_RN(Instr)          EXTRACT_BITRANGE(Instr, 15, 12)
#define ARM_BRANCH_EXTRACT_RS(Instr)          EXTRACT_BITRANGE(Instr, 11, 8)
#define ARM_BRANCH_EXTRACT_RM(Instr)          EXTRACT_BITRANGE(Instr, 3, 0)

namespace sasm { namespace instr { namespace arm {

mult::mult(const sasm::elf::elf& elf, uint64 addr)
  : arm_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _long = ARM_BRANCH_EXTRACT_LONG(instr);
  _unsigned = ARM_BRANCH_EXTRACT_UNSIGNED(instr);
  _accumulate = ARM_BRANCH_EXTRACT_ACCUMULATE(instr);
  _setcond = ARM_BRANCH_EXTRACT_SETCOND(instr);
  _rd_reg = ARM_BRANCH_EXTRACT_RD(instr);
  _rn_reg = ARM_BRANCH_EXTRACT_RN(instr);
  _rs_reg = ARM_BRANCH_EXTRACT_RS(instr);
  _rm_reg = ARM_BRANCH_EXTRACT_RM(instr);
}

void mult::dump_asm(std::ostream& out) const
{
  /* There is a notion of signedness only in long mode. */
  if (_long)
    out << (_unsigned ? "s" : "u");

  out << (_accumulate ? "mla" : "mul") << (_long ? "l" : "")
    << (_setcond ? "s" : "") << _get_cond() << " ";

  /* Register usage is not the same in long mode. */
  if (_long)
  {
    out << _get_reg_name(_rn_reg) << ", " << _get_reg_name(_rd_reg) << ", "
      << _get_reg_name(_rm_reg) << ", " << _get_reg_name(_rs_reg);
  }
  else
  {
    out << _get_reg_name(_rd_reg) << ", " << _get_reg_name(_rm_reg) << ", "
      << _get_reg_name(_rs_reg);

    /* Rn is used only in accumulate mode. */
    if (_accumulate)
      out << ", " << _get_reg_name(_rn_reg);
  }
}

}}}
