#ifndef INSTR_MIPS_ITYPE_LB_H_
# define INSTR_MIPS_ITYPE_LB_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct lb : public rt_immedrs_instr
{
  lb(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "lb"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_LB_H_ */
