#ifndef INSTR_MIPS_ITYPE_LW_H_
# define INSTR_MIPS_ITYPE_LW_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct lw : public rt_immedrs_instr
{
  lw(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "lw"; }
  virtual ~lw() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_LW_H_ */
