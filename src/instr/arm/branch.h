#ifndef INSTR_ARM_BRANCH_H_
# define INSTR_ARM_BRANCH_H_

# include <fwd.h>
# include <instr/arm/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace arm {

class branch : public arm_instr
{
public:
  branch(const sasm::elf::elf& elf, uint64 addr);
  virtual ~branch() {}
  virtual void dump_asm(std::ostream& out) const;

private:
  bool    _link;
  sint32  _offset;
};

}}}

#endif /* !INSTR_ARM_BRANCH_H_ */
