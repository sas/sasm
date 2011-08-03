#ifndef INSTR_MIPS_JTYPE_J_H_
# define INSTR_MIPS_JTYPE_J_H_

# include <pervasive.h>
# include <instr/mips/jtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace jtype {

class j : public jtype_instr
{
public:
  j(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_J_H_ */
