#ifndef INSTR_MIPS_JTYPE_JAL_H_
# define INSTR_MIPS_JTYPE_JAL_H_

# include <pervasive.h>
# include <instr/mips/jtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace jtype {

class jal : public jtype_instr
{
public:
  jal(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_JAL_H_ */
