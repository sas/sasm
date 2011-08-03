#ifndef INSTR_MIPS_MULTU_H_
# define INSTR_MIPS_MULTU_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class multu : public rtype_instr
{
public:
  multu(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_MULTU_H_ */
