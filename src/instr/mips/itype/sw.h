#ifndef INSTR_MIPS_ITYPE_SW_H_
# define INSTR_MIPS_ITYPE_SW_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct sw : public rt_immedrs_instr
{
  sw(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "sw"; }
  virtual ~sw() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_SW_H_ */
