#include "instr.h"

namespace sasm { namespace instr {

void instr::_dump_addr(std::ostream& out) const
{
  try
  {
    auto sym = _elf.symtab[_addr];

    if (sym.type == sasm::elf::symtab::symbol::sym_type::func)
      out << std::endl << sym.name << ":" << std::endl;
  }
  catch (std::out_of_range& e) {}

  out << "  0x" << std::hex << _addr << std::dec << ": ";
}

}}
