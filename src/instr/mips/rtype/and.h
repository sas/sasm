#ifndef INSTR_MIPS_AND_H_
# define INSTR_MIPS_AND_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the class and_ instead of and to avoid token collision. */
class and_ : public rtype_instr
{
public:
  and_(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_AND_H_ */
