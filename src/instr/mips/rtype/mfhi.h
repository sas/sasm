#ifndef INSTR_MIPS_MFHI_H_
# define INSTR_MIPS_MFHI_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class mfhi : public rtype_instr
{
public:
  mfhi(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_MFHI_H_ */