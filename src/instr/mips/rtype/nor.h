#ifndef INSTR_MIPS_RTYPE_NOR_H_
# define INSTR_MIPS_RTYPE_NOR_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct nor : public rd_rs_rt_instr
{
  nor(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "nor"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_NOR_H_ */
