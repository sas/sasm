#ifndef INSTR_MIPS_ITYPE_LUI_H_
# define INSTR_MIPS_ITYPE_LUI_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct lui : public rt_immed_instr
{
  lui(const sasm::elf::elf& elf, uint64 addr)
    : rt_immed_instr(elf, addr)
  { _name = "lui"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_LUI_H_ */
