#ifndef INSTR_MIPS_ITYPE_BLEZ_H_
# define INSTR_MIPS_ITYPE_BLEZ_H_

# include <instr/mips/itype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace itype {

struct blez : public rt_immedrs_instr
{
  blez(const sasm::elf::elf& elf, uint64 addr)
    : rt_immedrs_instr(elf, addr)
  { _name = "blez"; }
};

}}}}

#endif /* !INSTR_MIPS_ITYPE_BLEZ_H_ */
