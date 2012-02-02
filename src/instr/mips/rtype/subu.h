#ifndef INSTR_MIPS_RTYPE_SUBU_H_
# define INSTR_MIPS_RTYPE_SUBU_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct subu : public rd_rs_rt_instr
{
  subu(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "subu"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SUBU_H_ */
