#ifndef INSTR_MIPS_RTYPE_SLT_H_
# define INSTR_MIPS_RTYPE_SLT_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct slt : public rd_rs_rt_instr
{
  slt(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "slt"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SLT_H_ */
