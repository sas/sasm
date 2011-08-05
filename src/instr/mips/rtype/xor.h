#ifndef INSTR_MIPS_RTYPE_XOR_H_
# define INSTR_MIPS_RTYPE_XOR_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the struct xor_ instead of xor to avoid token collision. */
struct xor_ : public rd_rs_rt_instr
{
  xor_(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "xor"; }
  virtual ~xor_() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_XOR_H_ */
