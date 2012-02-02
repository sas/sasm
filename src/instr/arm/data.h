#ifndef INSTR_ARM_DATA_H_
# define INSTR_ARM_DATA_H_

# include <ostream>

# include <fwd.h>
# include <instr/arm/instr.h>

namespace sasm { namespace instr { namespace arm {

class data : public arm_instr
{
public:
  data(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;

private:
  bool  _immed;
  int   _opcode;
  bool  _setcond;
  int   _rn_reg;
  int   _rd_reg;
  int   _operand2;

  static std::string _get_operand2_str(int operand2, bool immed);

  static const std::string& _get_opcode_name(int opcode);
};

}}}

#endif /* !INSTR_ARM_DATA_H_ */
