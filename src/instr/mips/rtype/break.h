#ifndef INSTR_MIPS_BREAK_H_
# define INSTR_MIPS_BREAK_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the class break_ instead of break to avoid token collision. */
class break_ : public rtype_instr
{
public:
  break_(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_BREAK_H_ */
