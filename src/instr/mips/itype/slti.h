#ifndef INSTR_MIPS_ITYPE_SLTI_H_
# define INSTR_MIPS_ITYPE_SLTI_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct slti : public rt_rs_immed_instr
{
  slti(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "slti"; }
  virtual ~slti() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_SLTI_H_ */
