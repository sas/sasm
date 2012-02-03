#ifndef INSTR_MIPS_RTYPE_DIVU_H_
# define INSTR_MIPS_RTYPE_DIVU_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct divu : public rs_rt_instr
{
  divu(const sasm::elf::elf& elf, uint64 addr)
    : rs_rt_instr(elf, addr)
  { _name = "divu"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_DIVU_H_ */
