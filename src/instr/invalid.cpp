#include "invalid.h"

namespace sasm { namespace instr {

void invalid::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "invalid" << std::endl;
}

}}
