#ifndef INSTR_ARM_UNDEF_H_
# define INSTR_ARM_UNDEF_H_

# include <ostream>

# include <instr/arm/instr.h>

namespace sasm { namespace instr { namespace arm {

class undef : public arm_instr
{
public:
  undef(const sasm::elf::elf& elf, uint64 addr) : arm_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

}}}

#endif /* !INSTR_ARM_UNDEF_H_ */
