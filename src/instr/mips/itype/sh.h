#ifndef INSTR_MIPS_ITYPE_SH_H_
# define INSTR_MIPS_ITYPE_SH_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct sh : public rt_immedrs_instr
{
  sh(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "sh"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_SH_H_ */
