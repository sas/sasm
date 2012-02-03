#ifndef INSTR_MIPS_RTYPE_MFLO_H_
# define INSTR_MIPS_RTYPE_MFLO_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct mflo : public rd_instr
{
  mflo(const sasm::elf::elf& elf, uint64 addr)
    : rd_instr(elf, addr)
  { _name = "mflo"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MFLO_H_ */
