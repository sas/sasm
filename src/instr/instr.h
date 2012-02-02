#ifndef INSTR_INSTR_H_
# define INSTR_INSTR_H_

# include <ostream>

# include <elf/elf.h>

namespace sasm { namespace instr {

class instr
{
public:
  instr(const sasm::elf::elf& elf, uint64 addr) : _elf(elf), _addr(addr) {}
  virtual ~instr() {}
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  const sasm::elf::elf& _elf;
  uint64                _addr;
  std::string           _name;

  std::string _get_rela_addr(sint64 offset) const;
  std::string _get_abs_addr(uint64 addr) const;
};

}}

#endif /* !INSTR_INSTR_H_ */
