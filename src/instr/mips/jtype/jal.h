#ifndef INSTR_MIPS_JTYPE_JAL_H_
# define INSTR_MIPS_JTYPE_JAL_H_

# include <pervasive.h>
# include <instr/mips/jtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace jtype {

struct jal : public jtype_instr
{
  jal(const sasm::elf::elf& elf, uint64 addr)
    : jtype_instr(elf, addr)
  { _name = "jal"; }
  virtual ~jal() {}
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_JAL_H_ */
