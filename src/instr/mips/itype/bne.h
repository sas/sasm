#ifndef INSTR_MIPS_ITYPE_BNE_H_
# define INSTR_MIPS_ITYPE_BNE_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct bne : public rs_rt_label_instr
{
  bne(const sasm::elf::elf& elf, uint64 addr)
    : rs_rt_label_instr(elf, addr)
  { _name = "bne"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BNE_H_ */
