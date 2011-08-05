#include "instr.h"

#define MIPS_ITYPE_EXTRACT_RS(Instr)    ((Instr >> 21) & ((1 << 5) - 1))
#define MIPS_ITYPE_EXTRACT_RT(Instr)    ((Instr >> 16) & ((1 << 5) - 1))
#define MIPS_ITYPE_EXTRACT_IMMED(Instr) (Instr & 0xffff)

namespace sasm { namespace instr { namespace mips { namespace itype {

itype_instr::itype_instr(const sasm::elf::elf& elf, uint64 addr)
  : mips_instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _rs_reg = MIPS_ITYPE_EXTRACT_RS(instr);
  _rt_reg = MIPS_ITYPE_EXTRACT_RT(instr);
  _immed_val = MIPS_ITYPE_EXTRACT_IMMED(instr);
}

void rs_rt_label_instr::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << _name << " " << _get_reg_name(_rs_reg) << ", "
    << _get_reg_name(_rt_reg) << ", " << _get_rela_addr((_immed_val << 2) + 4)
    << std::endl;
}

}}}}
