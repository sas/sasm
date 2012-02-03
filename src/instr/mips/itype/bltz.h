#ifndef INSTR_MIPS_ITYPE_BLTZ_H_
# define INSTR_MIPS_ITYPE_BLTZ_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct bltz : public rt_immedrs_instr
{
  bltz(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "bltz"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BLTZ_H_ */
