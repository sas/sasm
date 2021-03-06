#ifndef INSTR_MIPS_RTYPE_DIV_H_
# define INSTR_MIPS_RTYPE_DIV_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct div : public rs_rt_instr
{
  div(const sasm::elf::elf& elf, uint64 addr)
    : rs_rt_instr(elf, addr)
  { _name = "div"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_DIV_H_ */
