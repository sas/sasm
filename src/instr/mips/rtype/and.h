#ifndef INSTR_MIPS_RTYPE_AND_H_
# define INSTR_MIPS_RTYPE_AND_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the struct and_ instead of and to avoid token collision. */
struct and_ : public rd_rs_rt_instr
{
  and_(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "and"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_AND_H_ */
