#ifndef INSTR_MIPS_RTYPE_JR_H_
# define INSTR_MIPS_RTYPE_JR_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct jr : public rs_instr
{
  jr(const sasm::elf::elf& elf, uint64 addr)
    : rs_instr(elf, addr)
  { _name = "jr"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_JR_H_ */
