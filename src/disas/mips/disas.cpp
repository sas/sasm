#include "disas.h"

#include <pervasive.h>
#include <instr/mips/nop.h>
#include <instr/mips/invalid.h>

namespace sasm { namespace disas {

mips_disas::mips_disas(const sasm::elf::elf& elf)
  : disas(elf)
{
}

sasm::instr::instr* mips_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  if (next == 0)
    res = new sasm::instr::mips::nop(_elf, _current_addr);
  else
    res = new sasm::instr::mips::invalid(_elf, _current_addr);

  _current_addr += 4; // Fixed size instructions

  return res;
}

}}
