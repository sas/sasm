#ifndef INSTR_MIPS_INVALID_H_
# define INSTR_MIPS_INVALID_H_

# include <pervasive.h>
# include <elf/elf.h>
# include <instr/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips {

class invalid : public instr
{
public:
  invalid(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}

#endif /* !INSTR_MIPS_INVALID_H_ */
