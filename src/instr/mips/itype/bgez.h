#ifndef INSTR_MIPS_ITYPE_BGEZ_H_
# define INSTR_MIPS_ITYPE_BGEZ_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct bgez : public rt_immedrs_instr
{
  bgez(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "bgez"; }
  virtual ~bgez() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BGEZ_H_ */
