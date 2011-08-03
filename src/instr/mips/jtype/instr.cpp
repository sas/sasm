#include "instr.h"

/* XXX: potential problem with negative offsets. */
#define MIPS_JTYPE_EXTRACT_TARGET(Instr) ((Instr >> 6) & ((1 << 26) - 1))

namespace sasm { namespace instr { namespace mips { namespace jtype {

jtype_instr::jtype_instr(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
  auto instr = elf.image.read<uint32>(addr);

  _target_val = MIPS_JTYPE_EXTRACT_TARGET(instr);
}

void jtype_instr::_dump_target_val(std::ostream& out) const
{
  /* XXX: Need to do real address resolution. */
  out << "0x" << std::hex << _target_val << std::dec;
}

}}}}
