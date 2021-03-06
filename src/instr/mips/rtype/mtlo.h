#ifndef INSTR_MIPS_RTYPE_MTLO_H_
# define INSTR_MIPS_RTYPE_MTLO_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct mtlo : public rs_instr
{
  mtlo(const sasm::elf::elf& elf, uint64 addr)
    : rs_instr(elf, addr)
  { _name = "mtlo"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_MTLO_H_ */
