#ifndef INSTR_MIPS_RTYPE_SLLV_H_
# define INSTR_MIPS_RTYPE_SLLV_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct sllv : public rd_rt_rs_instr
{
  sllv(const sasm::elf::elf& elf, uint64 addr)
    : rd_rt_rs_instr(elf, addr)
  { _name = "sllv"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SLLV_H_ */
