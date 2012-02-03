#ifndef INSTR_MIPS_JTYPE_INSTR_H_
# define INSTR_MIPS_JTYPE_INSTR_H_

# include <instr/mips/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace jtype {

class jtype_instr : public mips_instr
{
public:
  jtype_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;

protected:
  sint32 _target_val;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_INSTR_H_ */
