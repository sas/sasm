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

}}
