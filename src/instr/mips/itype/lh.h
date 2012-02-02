#ifndef INSTR_MIPS_ITYPE_LH_H_
# define INSTR_MIPS_ITYPE_LH_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct lh : public rt_immedrs_instr
{
  lh(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "lh"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_LH_H_ */
