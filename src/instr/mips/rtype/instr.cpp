#include "instr.h"

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
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rs_reg) << ", " << _get_reg_name(_rt_reg);
}

void noarg_instr::dump_asm(std::ostream& out) const
{
  out << _name;
}

void rs_rt_instr::dump_asm(std::ostream& out) const
{
  out << _name << " " << _get_reg_name(_rs_reg) << ", "
    << _get_reg_name(_rt_reg);
}

void rd_rs_instr::dump_asm(std::ostream& out) const
{
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rs_reg);
}

void rs_instr::dump_asm(std::ostream& out) const
{
  out << _name << " " << _get_reg_name(_rs_reg);
}

void rd_instr::dump_asm(std::ostream& out) const
{
  out << _name << " " << _get_reg_name(_rd_reg);
}

void rd_rt_sa_instr::dump_asm(std::ostream& out) const
{
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rt_reg) << ", 0x" << std::hex << _sa_val << std::dec;
}

void rd_rt_rs_instr::dump_asm(std::ostream& out) const
{
  out << _name << " " << _get_reg_name(_rd_reg) << ", "
    << _get_reg_name(_rs_reg) << ", " << _get_reg_name(_rt_reg);
}

}}}}
