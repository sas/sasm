#ifndef INSTR_MIPS_INSTR_H_
# define INSTR_MIPS_INSTR_H_

# include <elf/elf.h>
# include <instr/instr.h>

# include <ostream>
# include <string>

namespace sasm { namespace instr { namespace mips {

class mips_instr : public instr
{
public:
  mips_instr(const sasm::elf::elf& elf, uint64 addr) : instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  static const std::string& _get_reg_name(int reg);
};

}}}

#endif /* !INSTR_INSTR_H_ */
