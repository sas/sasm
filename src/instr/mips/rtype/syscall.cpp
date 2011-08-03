#include "syscall.h"

namespace sasm { namespace instr { namespace mips { namespace rtype {

syscall::syscall(const sasm::elf::elf& elf, uint64 addr)
  : rtype_instr(elf, addr)
{
}

void syscall::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "syscall";
  out << std::endl;
}

}}}}
