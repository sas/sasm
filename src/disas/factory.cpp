#include "factory.h"

#include <disas/arm/disas.h>
#include <disas/mips/disas.h>
#include <elf/elf.h>

#include <elf.h>

namespace sasm { namespace disas {

disas* factory(const sasm::elf::elf& elf)
{
  switch (elf.get_machine())
  {
    case EM_ARM:
      return new sasm::disas::arm_disas(elf);
    case EM_MIPS:
    case EM_MIPS_RS3_LE:
      return new sasm::disas::mips_disas(elf);
    default:
      return nullptr;
  }
}

}}
