#ifndef INSTR_MIPS_RTYPE_BREAK_H_
# define INSTR_MIPS_RTYPE_BREAK_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

/* Name the class break_ instead of break to avoid token collision. */
struct break_ : public noarg_instr
{
  break_(const sasm::elf::elf& elf, uint64 addr)
    : noarg_instr(elf, addr)
  { _name = "break"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_BREAK_H_ */
