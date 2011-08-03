#include "disas.h"

#include <pervasive.h>
#include <instr/mips/nop.h>

namespace sasm { namespace disas {

mips_disas::mips_disas(const sasm::elf::elf& elf)
  : disas(elf)
{
}

sasm::instr::instr* mips_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);

  if (next == 0)
    return new sasm::instr::mips::nop(_elf);
  else
    return nullptr;
}

}}
