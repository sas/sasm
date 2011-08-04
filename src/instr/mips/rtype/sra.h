#ifndef INSTR_MIPS_RTYPE_SRA_H_
# define INSTR_MIPS_RTYPE_SRA_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct sra : public rd_rt_sa_instr
{
  sra(const sasm::elf::elf& elf, uint64 addr)
    : rd_rt_sa_instr(elf, addr)
  { _name = "sra"; }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SRA_H_ */
