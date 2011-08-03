#ifndef INSTR_MIPS_ADD_H_
# define INSTR_MIPS_ADD_H_

# include <pervasive.h>
# include <instr/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips {

class add : public instr
{
public:
  add(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;

private:
  int reg_d, reg_s, reg_t;
};

}}}

#endif /* !INSTR_MIPS_ADD_H_ */
