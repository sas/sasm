#include "instr.h"

#include <sstream>

namespace sasm { namespace instr {

/*
** XXX: For the two following functions, we should return the target symbol name
** if possible.
*/

std::string instr::_get_rela_addr(sint64 offset) const
{
  std::ostringstream os;

  os << "0x" << std::hex << _addr + offset << std::dec;

  return os.str();
}

std::string instr::_get_abs_addr(uint64 addr) const
{
  std::ostringstream os;

  os << "0x" << std::hex << addr << std::dec;

  return os.str();
}

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
