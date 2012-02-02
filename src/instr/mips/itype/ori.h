#ifndef INSTR_MIPS_ITYPE_ORI_H_
# define INSTR_MIPS_ITYPE_ORI_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct ori : public rt_rs_immed_instr
{
  ori(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "ori"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_ORI_H_ */
