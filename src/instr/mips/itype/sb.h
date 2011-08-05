#ifndef INSTR_MIPS_ITYPE_SB_H_
# define INSTR_MIPS_ITYPE_SB_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct sb : public rt_immedrs_instr
{
  sb(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "sb"; }
  virtual ~sb() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_SB_H_ */
