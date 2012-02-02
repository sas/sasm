#ifndef INSTR_MIPS_ITYPE_BGTZ_H_
# define INSTR_MIPS_ITYPE_BGTZ_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct bgtz : public rt_immedrs_instr
{
  bgtz(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "bgtz"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BGTZ_H_ */
