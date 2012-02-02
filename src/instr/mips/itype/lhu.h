#ifndef INSTR_MIPS_ITYPE_LHU_H_
# define INSTR_MIPS_ITYPE_LHU_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct lhu : public rt_immedrs_instr
{
  lhu(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "lhu"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_LHU_H_ */
