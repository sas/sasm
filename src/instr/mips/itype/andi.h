#ifndef INSTR_MIPS_ITYPE_ANDI_H_
# define INSTR_MIPS_ITYPE_ANDI_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct andi : public rt_rs_immed_instr
{
  andi(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "andi"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_ANDI_H_ */
