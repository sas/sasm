#include "undef.h"

namespace sasm { namespace instr { namespace arm {

void undef::dump_asm(std::ostream& out) const
{
  out << "undef";
}

}}}
