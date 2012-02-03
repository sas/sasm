#ifndef INSTR_MIPS_ITYPE_ADDI_H_
# define INSTR_MIPS_ITYPE_ADDI_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct addi : public rt_rs_immed_instr
{
  addi(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "addi"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_ADDI_H_ */
