#ifndef INSTR_MIPS_ITYPE_BEQ_H_
# define INSTR_MIPS_ITYPE_BEQ_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct beq : public rs_rt_label_instr
{
  beq(const sasm::elf::elf& elf, uint64 addr)
    : rs_rt_label_instr(elf, addr)
  { _name = "beq"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BEQ_H_ */
