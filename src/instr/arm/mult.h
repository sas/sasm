#ifndef INSTR_ARM_MULT_H_
# define INSTR_ARM_MULT_H_

# include <fwd.h>
# include <instr/arm/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace arm {

class mult : public arm_instr
{
public:
  mult(const sasm::elf::elf& elf, uint64 addr);
  virtual ~mult() {}
  virtual void dump_asm(std::ostream& out) const;

private:
  bool  _long;
  bool  _unsigned;
  bool  _accumulate;
  bool  _setcond;
  int   _rd_reg;
  int   _rn_reg;
  int   _rs_reg;
  int   _rm_reg;
};

}}}

#endif /* !INSTR_ARM_MULT_H_ */
