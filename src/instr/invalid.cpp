#include "invalid.h"

namespace sasm { namespace instr {

void invalid::dump_asm(std::ostream& out) const
{
  out << "invalid";
}

}}
