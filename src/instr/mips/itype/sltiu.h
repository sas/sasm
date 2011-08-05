#ifndef INSTR_MIPS_ITYPE_SLTIU_H_
# define INSTR_MIPS_ITYPE_SLTIU_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct sltiu : public rt_rs_immed_instr
{
  sltiu(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "sltiu"; }
  virtual ~sltiu() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_SLTIU_H_ */
