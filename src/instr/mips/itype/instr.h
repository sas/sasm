#ifndef INSTR_MIPS_ITYPE_INSTR_H_
# define INSTR_MIPS_ITYPE_INSTR_H_

# include <pervasive.h>
# include <instr/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace itype {

class itype_instr : public instr
{
public:
  itype_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  void _dump_rs_reg(std::ostream& out) const;
  void _dump_rt_reg(std::ostream& out) const;
  void _dump_immed_val(std::ostream& out, bool as_addr = false) const;

  int     _rs_reg;
  int     _rt_reg;
  sint16  _immed_val;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_INSTR_H_ */
