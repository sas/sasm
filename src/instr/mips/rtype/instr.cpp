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
  _sa_reg = MIPS_RTYPE_EXTRACT_SA(instr);
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

void rtype_instr::_dump_sa_reg(std::ostream& out) const
{
  out << "$" << _sa_reg;
}

}}}}
