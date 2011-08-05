#include "disas.h"

#include <pervasive.h>

#include <vector>

#define MIPS_INSTR_COND(Instr)  (Instr >> 28)

namespace sasm { namespace disas {

sasm::instr::instr* arm_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  _cond = MIPS_INSTR_COND(next);

  _current_addr += 4; // Fixed size instructions

  return res;
}

}}
