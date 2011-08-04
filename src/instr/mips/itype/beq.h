#ifndef INSTR_MIPS_ITYPE_BEQ_H_
# define INSTR_MIPS_ITYPE_BEQ_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace itype {

class beq : public itype_instr
{
public:
  beq(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BEQ_H_ */
