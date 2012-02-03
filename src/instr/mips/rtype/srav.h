#ifndef INSTR_MIPS_RTYPE_SRAV_H_
# define INSTR_MIPS_RTYPE_SRAV_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct srav : public rd_rt_rs_instr
{
  srav(const sasm::elf::elf& elf, uint64 addr)
    : rd_rt_rs_instr(elf, addr)
  { _name = "srav"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SRAV_H_ */
