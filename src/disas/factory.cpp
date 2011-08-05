#include "factory.h"

#include <disas/mips/disas.h>
#include <elf/elf.h>

#include <elf.h>

namespace sasm { namespace disas {

disas* factory(const sasm::elf::elf& elf)
{
  int elf_machine = elf.get_machine();

  if (elf_machine == EM_MIPS || elf_machine == EM_MIPS_RS3_LE)
    return new sasm::disas::mips_disas(elf);
  else
    return nullptr;
}

}}
