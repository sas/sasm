#ifndef INSTR_MIPS_ITYPE_LBU_H_
# define INSTR_MIPS_ITYPE_LBU_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct lbu : public rt_immedrs_instr
{
  lbu(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "lbu"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_LBU_H_ */
