#ifndef INSTR_MIPS_DIVU_H_
# define INSTR_MIPS_DIVU_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class divu : public rtype_instr
{
public:
  divu(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_DIVU_H_ */
