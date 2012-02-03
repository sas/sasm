#ifndef INSTR_MIPS_ITYPE_INSTR_H_
# define INSTR_MIPS_ITYPE_INSTR_H_

# include <instr/mips/instr.h>

# include <ostream>

# define MIPS_ITYPE_EXTRACT_RS(Instr)     ((Instr >> 21) & ((1 << 5) - 1))
# define MIPS_ITYPE_EXTRACT_RT(Instr)     ((Instr >> 16) & ((1 << 5) - 1))
# define MIPS_ITYPE_EXTRACT_IMMED(Instr)  (Instr & 0xffff)

namespace sasm { namespace instr { namespace mips { namespace itype {

class itype_instr : public mips_instr
{
public:
  itype_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  void _dump_immed_val(std::ostream& out, bool as_addr = false) const;

  int     _rs_reg;
  int     _rt_reg;
  sint16  _immed_val;
};

struct rt_rs_immed_instr : public itype_instr
{
  rt_rs_immed_instr(const sasm::elf::elf& elf, uint64 addr) : itype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rs_rt_label_instr : public itype_instr
{
  rs_rt_label_instr(const sasm::elf::elf& elf, uint64 addr) : itype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rs_label_instr : public itype_instr
{
  rs_label_instr(const sasm::elf::elf& elf, uint64 addr) : itype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rt_immedrs_instr : public itype_instr
{
  rt_immedrs_instr(const sasm::elf::elf& elf, uint64 addr) : itype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rt_immed_instr : public itype_instr
{
  rt_immed_instr(const sasm::elf::elf& elf, uint64 addr) : itype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_JTYPE_INSTR_H_ */
