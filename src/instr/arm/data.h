#ifndef INSTR_ARM_DATA_H_
# define INSTR_ARM_DATA_H_

# include <fwd.h>
# include <instr/arm/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace arm {

class data : public arm_instr
{
public:
  data(const sasm::elf::elf& elf, uint64 addr);
  virtual ~data() {}
  virtual void dump_asm(std::ostream& out) const;

private:
  bool  _immed;
  int   _opcode;
  bool  _setcond;
  int   _rn_reg;
  int   _rd_reg;
  int   _operand2;

  static const std::string& _get_opcode_name(int opcode);
  static std::string _get_operand2_str(int operand2, bool immed);
};

}}}

#endif /* !INSTR_ARM_DATA_H_ */
