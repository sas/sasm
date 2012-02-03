#ifndef INSTR_MIPS_RTYPE_ADD_H_
# define INSTR_MIPS_RTYPE_ADD_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct add : public rd_rs_rt_instr
{
  add(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "add"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_ADD_H_ */
