#ifndef INSTR_INVALID_H_
# define INSTR_INVALID_H_

# include <ostream>

# include <instr/instr.h>

namespace sasm { namespace instr {

class invalid : public instr
{
public:
  invalid(const sasm::elf::elf& elf, uint64 addr) : instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

}}

#endif /* !INSTR_INVALID_H_ */
