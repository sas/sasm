#ifndef INSTR_MIPS_RTYPE_MFHI_H_
# define INSTR_MIPS_RTYPE_MFHI_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct mfhi : public rd_instr
{
  mfhi(const sasm::elf::elf& elf, uint64 addr)
    : rd_instr(elf, addr)
  { _name = "mfhi"; }
  virtual ~mfhi() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MFHI_H_ */
