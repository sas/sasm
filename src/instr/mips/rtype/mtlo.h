#ifndef INSTR_MIPS_MTLO_H_
# define INSTR_MIPS_MTLO_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class mtlo : public rtype_instr
{
public:
  mtlo(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_MTLO_H_ */
