#ifndef INSTR_MIPS_ITYPE_BNE_H_
# define INSTR_MIPS_ITYPE_BNE_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace itype {

class bne : public itype_instr
{
public:
  bne(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BNE_H_ */
