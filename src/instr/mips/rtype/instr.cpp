#include "instr.h"

#define MIPS_RTYPE_EXTRACT_RS(Instr) ((Instr >> 21) & ((1 << 5) - 1))
#define MIPS_RTYPE_EXTRACT_RT(Instr) ((Instr >> 16) & ((1 << 5) - 1))
#define MIPS_RTYPE_EXTRACT_RD(Instr) ((Instr >> 11) & ((1 << 5) - 1))
#define MIPS_RTYPE_EXTRACT_SA(Instr) ((Instr >> 6) & ((1 << 5) - 1))

namespace sasm { namespace instr { namespace mips { namespace rtype {

rtype_instr::rtype_instr(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _rs_reg = MIPS_RTYPE_EXTRACT_RS(instr);
  _rt_reg = MIPS_RTYPE_EXTRACT_RT(instr);
  _rd_reg = MIPS_RTYPE_EXTRACT_RD(instr);
  _sa_val = MIPS_RTYPE_EXTRACT_SA(instr);
}

void rtype_instr::_dump_rs_reg(std::ostream& out) const
{
  out << "$" << _rs_reg;
}

void rtype_instr::_dump_rt_reg(std::ostream& out) const
{
  out << "$" << _rt_reg;
}

void rtype_instr::_dump_rd_reg(std::ostream& out) const
{
  out << "$" << _rd_reg;
}

void rtype_instr::_dump_sa_val(std::ostream& out) const
{
  out << "0x" << std::hex << _sa_val << std::dec;
}

void rd_rs_rt_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

void noarg_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name;
  out << std::endl;
}

void rs_rt_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << std::endl;
}

void rd_rs_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << std::endl;
}

void rs_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rs_reg(out);
  out << std::endl;
}

void rd_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rd_reg(out);
  out << std::endl;
}

void rd_rt_sa_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_sa_val(out);
  out << std::endl;
}

void rd_rt_rs_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rd_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_rs_reg(out);
  out << std::endl;
}

}}}}
