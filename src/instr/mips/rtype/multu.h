#ifndef INSTR_MIPS_RTYPE_MULTU_H_
# define INSTR_MIPS_RTYPE_MULTU_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct multu : public rs_rt_instr
{
  multu(const sasm::elf::elf& elf, uint64 addr)
    : rs_rt_instr(elf, addr)
  { _name = "multu"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MULTU_H_ */
