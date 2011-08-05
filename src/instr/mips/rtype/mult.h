#ifndef INSTR_MIPS_RTYPE_MULT_H_
# define INSTR_MIPS_RTYPE_MULT_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct mult : public rs_rt_instr
{
  mult(const sasm::elf::elf& elf, uint64 addr)
    : rs_rt_instr(elf, addr)
  { _name = "mult"; }
  virtual ~mult() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MULT_H_ */
