#include "disas.h"

#include <pervasive.h>
#include <instr/mips/invalid.h>
#include <instr/mips/nop.h>
#include <instr/mips/rtype/add.h>

#define MIPS_INSTR_OPCODE(Instr)    (Instr >> 26)
#define MIPS_RTYPE_FUNCTION(Instr)  (Instr & ((1 << 6) - 1))

namespace sasm { namespace disas {

mips_disas::mips_disas(const sasm::elf::elf& elf)
  : disas(elf)
{
}

sasm::instr::instr* mips_disas::_next_rtype_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);

  switch (MIPS_RTYPE_FUNCTION(next))
  {
    case 0x00: // sll
    case 0x02: // srl
    case 0x03: // sra
    case 0x04: // sllv
    case 0x06: // srlv
    case 0x07: // srav
    case 0x08: // jr
    case 0x09: // jalr
    case 0x0c: // syscall
    case 0x0d: // break
    case 0x10: // mfhi
    case 0x11: // mthi
    case 0x12: // mflo
    case 0x13: // mtlo
    case 0x18: // mult
    case 0x19: // multu
    case 0x1a: // div
    case 0x1b: // divu
    case 0x20:
      return new sasm::instr::mips::rtype::add(_elf, _current_addr);
    case 0x21: // addu
    case 0x22: // sub
    case 0x23: // subu
    case 0x24: // and
    case 0x25: // or
    case 0x26: // xor
    case 0x27: // nor
    case 0x2a: // slt
    case 0x2b: // sltu
    default:
      return new sasm::instr::mips::invalid(_elf, _current_addr);
  }
}

sasm::instr::instr* mips_disas::_next_itype_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  return res;
}

sasm::instr::instr* mips_disas::_next_jtype_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  return res;
}

sasm::instr::instr* mips_disas::_next_coproc_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  return res;
}

sasm::instr::instr* mips_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  /* Short circuit for nop. */
  if (next == 0)
  {
    _current_addr += 4;
    return new sasm::instr::mips::nop(_elf, _current_addr);
  }

  switch (MIPS_INSTR_OPCODE(next))
  {
    case 0x00:
      res = _next_rtype_instr();
      break;
    case 0x02:
    case 0x03:
      res = _next_jtype_instr();
      break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      res = _next_coproc_instr();
      break;
    default:
      res = _next_itype_instr();
  }

  _current_addr += 4; // Fixed size instructions

  return res;
}

}}
