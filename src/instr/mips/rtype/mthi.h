#ifndef INSTR_MIPS_RTYPE_MTHI_H_
# define INSTR_MIPS_RTYPE_MTHI_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class mthi : public rtype_instr
{
public:
  mthi(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MTHI_H_ */
