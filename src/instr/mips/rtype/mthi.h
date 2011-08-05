#ifndef INSTR_MIPS_RTYPE_MTHI_H_
# define INSTR_MIPS_RTYPE_MTHI_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct mthi : public rs_instr
{
  mthi(const sasm::elf::elf& elf, uint64 addr)
    : rs_instr(elf, addr)
  { _name = "mthi"; }
  virtual ~mthi() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MTHI_H_ */
