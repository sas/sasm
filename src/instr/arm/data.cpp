#include "data.h"

#include <elf/elf.h>

#include <map>
#include <sstream>

#define ARM_DATA_EXTRACT_IMMED(Instr)     ((Instr >> 25) & 1)
#define ARM_DATA_EXTRACT_OPCODE(Instr)    ((Instr & ((1 << 25) - 1)) >> 21)
#define ARM_DATA_EXTRACT_SETCOND(Instr)   ((Instr >> 20) & 1)
#define ARM_DATA_EXTRACT_RN(Instr)        ((Instr & ((1 << 20) - 1)) >> 16)
#define ARM_DATA_EXTRACT_RD(Instr)        ((Instr & ((1 << 16) - 1)) >> 12)
#define ARM_DATA_EXTRACT_OPERAND2(Instr)  (Instr & ((1 << 12) - 1))

namespace sasm { namespace instr { namespace arm {

data::data(const sasm::elf::elf& elf, uint64 addr)
  : arm_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _immed = ARM_DATA_EXTRACT_IMMED(instr);
  _opcode = ARM_DATA_EXTRACT_OPCODE(instr);
  _setcond = ARM_DATA_EXTRACT_SETCOND(instr);
  _rn_reg = ARM_DATA_EXTRACT_RN(instr);
  _rn_reg = ARM_DATA_EXTRACT_RN(instr);
  _rd_reg = ARM_DATA_EXTRACT_RD(instr);
  _operand2 = ARM_DATA_EXTRACT_OPERAND2(instr);
}

void data::dump_asm(std::ostream& out) const
{
  
  out << _get_opcode_name(_opcode) << (_setcond ? "s" : "") << _get_cond();
  out << " " << _get_reg_name(_rd_reg) << ", ";

  if (_opcode != 0xd && _opcode != 0xf) /* mov and mvn do not use the Rn register. */
    out << _get_reg_name(_rn_reg) << ", ";
  
  out << _get_operand2_str(_operand2, _immed);
}

const std::string& data::_get_opcode_name(int opcode)
{
  static std::map<int, std::string> opcode_to_str = {
    { 0x00, "and" },  { 0x01, "eor" },  { 0x02, "sub" },  { 0x03, "rsb" },
    { 0x04, "add" },  { 0x05, "adc" },  { 0x06, "sbc" },  { 0x07, "rsc" },
    { 0x08, "tst" },  { 0x09, "teq" },  { 0x0a, "cmp" },  { 0x0b, "cmn" },
    { 0x0c, "orr" },  { 0x0d, "mov" },  { 0x0e, "bic" },  { 0x0f, "mvn" },
  };

  return opcode_to_str[opcode];
}

std::string data::_get_operand2_str(int operand2, bool immed)
{
  static std::map<int, std::string> shift_type_to_str = {
    { 0x0, "lsl" }, { 0x1, "lsr" }, { 0x2, "asr" }, { 0x3, "ror" }
  };

  std::ostringstream os;

  if (!immed)
  {
    int reg = operand2 & 0xf;
    int shift_type = (operand2 >> 5) & 0x3;

    os << _get_reg_name(reg);

    if (operand2 & (1 << 4))
    {
      int shift_register = (operand2 & ((1 << 12) - 1)) >> 8;

      os << ", " << shift_type_to_str[shift_type] << " "
        << _get_reg_name(shift_register);
    }
    else
    {
      int shift_amount = (operand2 & ((1 << 12) - 1)) >> 7;

      if (shift_amount != 0) /* No need to print a null shift. */
        os << ", " << shift_type_to_str[shift_type] << " #" << shift_amount;
    }
  }
  else
  {
    int value = operand2 & 0xff;
    int rotate = (operand2 >> 8) * 2;

    os << "#" << ((value >> rotate) | (value << (32 - rotate)));
  }

  return os.str();
}

}}}
