#ifndef INSTR_MIPS_RTYPE_SRLV_H_
# define INSTR_MIPS_RTYPE_SRLV_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct srlv : public rd_rt_rs_instr
{
  srlv(const sasm::elf::elf& elf, uint64 addr)
    : rd_rt_rs_instr(elf, addr)
  { _name = "srlv"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SRLV_H_ */
