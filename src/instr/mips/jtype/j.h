#ifndef INSTR_MIPS_JTYPE_J_H_
# define INSTR_MIPS_JTYPE_J_H_

# include <pervasive.h>
# include <instr/mips/jtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace jtype {

struct j : public jtype_instr
{
  j(const sasm::elf::elf& elf, uint64 addr)
    : jtype_instr(elf, addr)
  { _name = "j"; }
  virtual ~j() {}
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_J_H_ */
