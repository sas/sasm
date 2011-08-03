#include "instr.h"

namespace sasm { namespace instr {

instr::instr(const sasm::elf::elf& elf, uint64 addr)
  : _elf(elf), _addr(addr)
{
}

void instr::_dump_addr(std::ostream& out) const
{
  out << "0x" << std::hex << _addr << std::dec << ": ";
}

}}
