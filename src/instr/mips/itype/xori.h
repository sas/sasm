#ifndef INSTR_MIPS_ITYPE_XORI_H_
# define INSTR_MIPS_ITYPE_XORI_H_

# include <pervasive.h>
# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct xori : public rt_rs_immed_instr
{
  xori(const sasm::elf::elf& elf, uint64 addr)
    : rt_rs_immed_instr(elf, addr)
  { _name = "xori"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_XORI_H_ */
