#ifndef INSTR_MIPS_OR_H_
# define INSTR_MIPS_OR_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the class or_ instead of or to avoid token collision. */
class or_ : public rtype_instr
{
public:
  or_(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_OR_H_ */