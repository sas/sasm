#include "instr.h"

#define MIPS_ITYPE_EXTRACT_RS(Instr)    ((Instr >> 21) & ((1 << 5) - 1))
#define MIPS_ITYPE_EXTRACT_RT(Instr)    ((Instr >> 16) & ((1 << 5) - 1))
#define MIPS_ITYPE_EXTRACT_IMMED(Instr) (Instr & 0xffff)

namespace sasm { namespace instr { namespace mips { namespace itype {

itype_instr::itype_instr(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _rs_reg = MIPS_ITYPE_EXTRACT_RS(instr);
  _rt_reg = MIPS_ITYPE_EXTRACT_RT(instr);
  _immed_val = MIPS_ITYPE_EXTRACT_IMMED(instr);
}

void itype_instr::_dump_rs_reg(std::ostream& out) const
{
  out << "$" << _rs_reg;
}

void itype_instr::_dump_rt_reg(std::ostream& out) const
{
  out << "$" << _rt_reg;
}

void itype_instr::_dump_immed_val(std::ostream& out, bool as_addr) const
{
  if (as_addr)
    out << "0x" << std::hex << _addr + (_immed_val << 2) + 4 << std::dec;
  else
    out << "0x" << std::hex << _immed_val << std::dec;
}

rs_rt_label_instr::rs_rt_label_instr(const sasm::elf::elf& elf, uint64 addr)
  : itype_instr(elf, addr)
{
}

void rs_rt_label_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " ";
  _dump_rs_reg(out);
  out << ", ";
  _dump_rt_reg(out);
  out << ", ";
  _dump_immed_val(out, true);
  out << std::endl;
}

}}}}
