#ifndef INSTR_ARM_BX_H_
# define INSTR_ARM_BX_H_

# include <fwd.h>
# include <instr/arm/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace arm {

class bx : public arm_instr
{
public:
  bx(const sasm::elf::elf& elf, uint64 addr);
  virtual ~bx() {}
  virtual void dump_asm(std::ostream& out) const;

private:
  int _rn_reg;
};

}}}

#endif /* !INSTR_ARM_BX_H_ */