#ifndef INSTR_MIPS_ITYPE_ADDIU_H_
# define INSTR_MIPS_ITYPE_ADDIU_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct addiu : public rt_rs_immed_instr
{
  addiu(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "addiu"; }
  virtual ~addiu() {}
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_ADDIU_H_ */
