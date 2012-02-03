#ifndef INSTR_MIPS_RTYPE_SRL_H_
# define INSTR_MIPS_RTYPE_SRL_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct srl : public rd_rt_sa_instr
{
  srl(const sasm::elf::elf& elf, uint64 addr)
    : rd_rt_sa_instr(elf, addr)
  { _name = "slr"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SRL_H_ */
