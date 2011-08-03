#ifndef INSTR_MIPS_NOP_H_
# define INSTR_MIPS_NOP_H_

# include <pervasive.h>
# include <elf/elf.h>
# include <instr/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips {

class nop : public instr
{
public:
  nop(const sasm::elf::elf& elf);
  virtual void dump_asm(std::ostream& out) const;
};

}}}

#endif /* !INSTR_MIPS_NOP_H_ */
