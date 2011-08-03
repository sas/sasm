#ifndef INSTR_INSTR_H_
# define INSTR_INSTR_H_

# include <elf/elf.h>

# include <ostream>

namespace sasm { namespace instr {

class instr
{
public:
  instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  const sasm::elf::elf& _elf;
  uint64 _addr;
};

}}

#endif /* !INSTR_INSTR_H_ */
