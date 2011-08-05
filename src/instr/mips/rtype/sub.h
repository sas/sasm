#ifndef INSTR_MIPS_RTYPE_SUB_H_
# define INSTR_MIPS_RTYPE_SUB_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct sub : public rd_rs_rt_instr
{
  sub(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "sub"; }
  virtual ~sub() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SUB_H_ */
