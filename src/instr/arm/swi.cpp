#include "swi.h"

namespace sasm { namespace instr { namespace arm {

void swi::dump_asm(std::ostream& out) const
{
  out << "svc" << _get_cond();
}

}}}
