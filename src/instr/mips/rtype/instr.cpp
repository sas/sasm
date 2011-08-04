#include "instr.h"

#define MIPS_RTYPE_EXTRACT_RS(Instr) ((Instr >> 21) & ((1 << 5) - 1))
#define MIPS_RTYPE_EXTRACT_RT(Instr) ((Instr >> 16) & ((1 << 5) - 1))
#define MIPS_RTYPE_EXTRACT_RD(Instr) ((Instr >> 11) & ((1 << 5) - 1))
#define MIPS_RTYPE_EXTRACT_SA(Instr) ((Instr >> 6) & ((1 << 5) - 1))

namespace sasm { namespace instr { namespace mips { namespace rtype {

rtype_instr::rtype_instr(const sasm::elf::elf& elf, uint64 addr)
  : mips_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _rs_reg = MIPS_RTYPE_EXTRACT_RS(instr);
  _rt_reg = MIPS_RTYPE_EXTRACT_RT(instr);
  _rd_reg = MIPS_RTYPE_EXTRACT_RD(instr);
  _sa_val = MIPS_RTYPE_EXTRACT_SA(instr);
}

void rd_rs_rt_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rs_reg) << ", " << _get_reg_name(_rt_reg) << std::endl;
}

void noarg_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << std::endl;
}

void rs_rt_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rs_reg) << ", "
    << _get_reg_name(_rt_reg) << std::endl;
}

void rd_rs_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rs_reg) << std::endl;
}

void rs_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rs_reg) << std::endl;
}

void rd_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rd_reg) << std::endl;
}

void rd_rt_sa_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rt_reg) << ", 0x" << std::hex << _sa_val << std::dec
    << std::endl;
}

void rd_rt_rs_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rs_reg) << ", " << _get_reg_name(_rt_reg) << std::endl;
}

}}}}
