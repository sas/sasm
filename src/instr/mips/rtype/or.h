#ifndef INSTR_MIPS_RTYPE_OR_H_
# define INSTR_MIPS_RTYPE_OR_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the struct or_ instead of or to avoid token collision. */
struct or_ : public rd_rs_rt_instr
{
  or_(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "or"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_OR_H_ */
