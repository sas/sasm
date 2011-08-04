#ifndef INSTR_MIPS_JTYPE_INSTR_H_
# define INSTR_MIPS_JTYPE_INSTR_H_

# include <pervasive.h>
# include <instr/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace jtype {

class jtype_instr : public instr
{
public:
  jtype_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;

protected:
  void _dump_target_val(std::ostream& out) const;

  sint32      _target_val;
  const char* _name;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_INSTR_H_ */
