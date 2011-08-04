#ifndef INSTR_MIPS_RTYPE_XOR_H_
# define INSTR_MIPS_RTYPE_XOR_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the class xor_ instead of xor to avoid token collision. */
class xor_ : public rtype_instr
{
public:
  xor_(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_XOR_H_ */
