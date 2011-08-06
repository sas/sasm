#include "swi.h"

namespace sasm { namespace instr { namespace arm {

void swi::dump_asm(std::ostream& out) const
{
  _dump_addr(out);
  out << "swi" << std::endl;
}

}}}
