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

  int         _rs_reg;
  int         _rt_reg;
  sint16      _immed_val;
  const char* _name;
};

struct rt_rs_immed_instr : public itype_instr
{
  rt_rs_immed_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

struct rs_rt_label_instr : public itype_instr
{
  rs_rt_label_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

struct rs_label_instr : public itype_instr
{
  rs_label_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

struct rt_immedrs_instr : public itype_instr
{
  rt_immedrs_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

struct rt_immed_instr : public itype_instr
{
  rt_immed_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_INSTR_H_ */
