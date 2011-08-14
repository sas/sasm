
#ifndef INSTR_MIPS_INSTR_H_
# define INSTR_MIPS_INSTR_H_

# include <fwd.h>
# include <instr/instr.h>

# include <ostream>
# include <string>

namespace sasm { namespace instr { namespace arm {

class arm_instr : public instr
{
public:
  arm_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual ~arm_instr() {}
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  byte _cond;

  static const std::string& _get_reg_name(int reg);

  const std::string& _get_cond() const;
};

}}}

#endif /* !INSTR_INSTR_H_ */
