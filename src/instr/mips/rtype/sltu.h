#ifndef INSTR_MIPS_RTYPE_SLTU_H_
# define INSTR_MIPS_RTYPE_SLTU_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct sltu : public rd_rs_rt_instr
{
  sltu(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "sltu"; }
  virtual ~sltu() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SLTU_H_ */
