#ifndef INSTR_ARM_SWI_H_
# define INSTR_ARM_SWI_H_

# include <ostream>

# include <fwd.h>
# include <instr/arm/instr.h>

namespace sasm { namespace instr { namespace arm {

class swi : public arm_instr
{
public:
  swi(const sasm::elf::elf& elf, uint64 addr) : arm_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

}}}

#endif /* !INSTR_ARM_SWI_H_ */
