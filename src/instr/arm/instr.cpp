#include <map>

#include "instr.h"

#define ARM_INSTR_COND(Instr) (Instr >> 28)

namespace sasm { namespace instr { namespace arm {

arm_instr::arm_instr(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _cond = ARM_INSTR_COND(instr);
}

const std::string& arm_instr::_get_reg_name(int reg)
{
  static std::map<int, std::string> reg_to_str = {
    { 0x00, "r0" }, { 0x01, "r1" }, { 0x02, "r2" }, { 0x03, "r3" },
    { 0x04, "r4" }, { 0x05, "r5" }, { 0x06, "r6" }, { 0x07, "r7" },
    { 0x08, "r8" }, { 0x09, "r9" }, { 0x0a, "sl" }, { 0x0b, "fp" },
    { 0x0c, "ip" }, { 0x0d, "sp" }, { 0x0e, "lr" }, { 0x0f, "pc" },
  };

  return reg_to_str[reg];
}

const std::string& arm_instr::_get_cond() const
{
  static std::map<int, std::string> cond_to_str = {
    { 0x00, "eq" }, { 0x01, "ne" }, { 0x02, "cs" }, { 0x03, "cc" },
    { 0x04, "mi" }, { 0x05, "pl" }, { 0x06, "vs" }, { 0x07, "vc" },
    { 0x08, "hi" }, { 0x09, "ls" }, { 0x0a, "ge" }, { 0x0b, "lt" },
    { 0x0c, "gt" }, { 0x0d, "le" }, { 0x0e, ""}
  };

  return cond_to_str[_cond];
}

}}}
