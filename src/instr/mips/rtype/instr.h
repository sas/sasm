#ifndef INSTR_MIPS_RTYPE_INSTR_H_
# define INSTR_MIPS_RTYPE_INSTR_H_

# include <instr/instr.h>

# include <ostream>

namespace sasm { namespace instr { namespace mips { namespace rtype {

class rtype_instr : public instr
{
public:
  rtype_instr(const sasm::elf::elf& elf, uint64 addr);
  virtual void dump_asm(std::ostream& out) const = 0;

protected:
  void _dump_rs_reg(std::ostream& out) const;
  void _dump_rt_reg(std::ostream& out) const;
  void _dump_rd_reg(std::ostream& out) const;
  void _dump_sa_val(std::ostream& out) const;

  int         _rs_reg;
  int         _rt_reg;
  int         _rd_reg;
  int         _sa_val;
  const char* _name;
};

struct rd_rs_rt_instr : public rtype_instr
{
  rd_rs_rt_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct noarg_instr : public rtype_instr
{
  noarg_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rs_rt_instr : public rtype_instr
{
  rs_rt_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rd_rs_instr : public rtype_instr
{
  rd_rs_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rs_instr : public rtype_instr
{
  rs_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rd_instr : public rtype_instr
{
  rd_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rd_rt_sa_instr : public rtype_instr
{
  rd_rt_sa_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

struct rd_rt_rs_instr : public rtype_instr
{
  rd_rt_rs_instr(const sasm::elf::elf& elf, uint64 addr) : rtype_instr(elf, addr) {}
  virtual void dump_asm(std::ostream& out) const;
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_INSTR_H_ */
