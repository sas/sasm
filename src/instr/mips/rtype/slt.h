#ifndef INSTR_MIPS_RTYPE_SLT_H_
# define INSTR_MIPS_RTYPE_SLT_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class slt : public rtype_instr
{
public:
  slt(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SLT_H_ */
