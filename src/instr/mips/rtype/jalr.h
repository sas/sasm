#ifndef INSTR_MIPS_RTYPE_JALR_H_
# define INSTR_MIPS_RTYPE_JALR_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct jalr : public rd_rs_instr
{
  jalr(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_instr(elf, addr)
  { _name = "jalr"; }
  virtual ~jalr() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_JALR_H_ */
