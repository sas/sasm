#ifndef DISAS_DISAS_H_
# define DISAS_DISAS_H_

# include <fwd.h>
# include <pervasive.h>
# include <elf/elf.h>

namespace sasm { namespace disas {

class disas
{
public:
  disas(const sasm::elf::elf& elf) : _elf(elf), _current_addr(elf.get_entry()) {}
  virtual ~disas() {}
  virtual sasm::instr::instr* next_instr() = 0;

  void set_addr(uint64 addr) { _current_addr = addr; }
  uint64 get_addr() const { return _current_addr; }

protected:
  const sasm::elf::elf& _elf;
  uint64 _current_addr;
};

}}

#endif /* !DISAS_DISAS_H_ */
