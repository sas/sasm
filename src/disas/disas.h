#ifndef DISAS_DISAS_H_
# define DISAS_DISAS_H_

# include <fwd.h>
# include <pervasive.h>

namespace sasm { namespace disas {

class disas
{
public:
  disas(const sasm::elf::elf& elf);
  virtual sasm::instr::instr* next_instr() = 0;

protected:
  const sasm::elf::elf& _elf;
  uint64 _current_addr;
};

}}

#endif /* !DISAS_DISAS_H_ */
