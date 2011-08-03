#include "disas.h"

#include <pervasive.h>
#include <instr/mips/invalid.h>
#include <instr/mips/jtype/j.h>
#include <instr/mips/jtype/jal.h>
#include <instr/mips/rtype/add.h>
#include <instr/mips/rtype/addu.h>
#include <instr/mips/rtype/and.h>
#include <instr/mips/rtype/break.h>
#include <instr/mips/rtype/div.h>
#include <instr/mips/rtype/divu.h>
#include <instr/mips/rtype/jalr.h>
#include <instr/mips/rtype/jr.h>
#include <instr/mips/rtype/mfhi.h>
#include <instr/mips/rtype/mflo.h>
#include <instr/mips/rtype/mthi.h>
#include <instr/mips/rtype/mtlo.h>
#include <instr/mips/rtype/mult.h>
#include <instr/mips/rtype/multu.h>
#include <instr/mips/rtype/nor.h>
#include <instr/mips/rtype/or.h>
#include <instr/mips/rtype/sll.h>
#include <instr/mips/rtype/sllv.h>
#include <instr/mips/rtype/slt.h>
#include <instr/mips/rtype/sltu.h>
#include <instr/mips/rtype/sra.h>
#include <instr/mips/rtype/srav.h>
#include <instr/mips/rtype/srl.h>
#include <instr/mips/rtype/srlv.h>
#include <instr/mips/rtype/sub.h>
#include <instr/mips/rtype/subu.h>
#include <instr/mips/rtype/syscall.h>
#include <instr/mips/rtype/xor.h>

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
    case 0x00: return new sasm::instr::mips::rtype::sll(_elf, _current_addr);
    case 0x02: return new sasm::instr::mips::rtype::srl(_elf, _current_addr);
    case 0x03: return new sasm::instr::mips::rtype::sra(_elf, _current_addr);
    case 0x04: return new sasm::instr::mips::rtype::sllv(_elf, _current_addr);
    case 0x06: return new sasm::instr::mips::rtype::srlv(_elf, _current_addr);
    case 0x07: return new sasm::instr::mips::rtype::srav(_elf, _current_addr);
    case 0x08: return new sasm::instr::mips::rtype::jr(_elf, _current_addr);
    case 0x09: return new sasm::instr::mips::rtype::jalr(_elf, _current_addr);
    case 0x0c: return new sasm::instr::mips::rtype::syscall(_elf, _current_addr);
    case 0x0d: return new sasm::instr::mips::rtype::break_(_elf, _current_addr);
    case 0x10: return new sasm::instr::mips::rtype::mfhi(_elf, _current_addr);
    case 0x11: return new sasm::instr::mips::rtype::mthi(_elf, _current_addr);
    case 0x12: return new sasm::instr::mips::rtype::mflo(_elf, _current_addr);
    case 0x13: return new sasm::instr::mips::rtype::mtlo(_elf, _current_addr);
    case 0x18: return new sasm::instr::mips::rtype::mult(_elf, _current_addr);
    case 0x19: return new sasm::instr::mips::rtype::multu(_elf, _current_addr);
    case 0x1a: return new sasm::instr::mips::rtype::div(_elf, _current_addr);
    case 0x1b: return new sasm::instr::mips::rtype::divu(_elf, _current_addr);
    case 0x20: return new sasm::instr::mips::rtype::add(_elf, _current_addr);
    case 0x21: return new sasm::instr::mips::rtype::addu(_elf, _current_addr);
    case 0x22: return new sasm::instr::mips::rtype::sub(_elf, _current_addr);
    case 0x23: return new sasm::instr::mips::rtype::subu(_elf, _current_addr);
    case 0x24: return new sasm::instr::mips::rtype::and_(_elf, _current_addr);
    case 0x25: return new sasm::instr::mips::rtype::or_(_elf, _current_addr);
    case 0x26: return new sasm::instr::mips::rtype::xor_(_elf, _current_addr);
    case 0x27: return new sasm::instr::mips::rtype::nor(_elf, _current_addr);
    case 0x2a: return new sasm::instr::mips::rtype::slt(_elf, _current_addr);
    case 0x2b: return new sasm::instr::mips::rtype::sltu(_elf, _current_addr);
    default: return new sasm::instr::mips::invalid(_elf, _current_addr);
  }
}

sasm::instr::instr* mips_disas::_next_itype_instr()
{
  return new sasm::instr::mips::invalid(_elf, _current_addr);
}

sasm::instr::instr* mips_disas::_next_jtype_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);

  switch (MIPS_INSTR_OPCODE(next))
  {
    case 0x02: return new sasm::instr::mips::jtype::j(_elf, _current_addr);
    case 0x03: return new sasm::instr::mips::jtype::jal(_elf, _current_addr);
    default: return new sasm::instr::mips::invalid(_elf, _current_addr);
  }
}

sasm::instr::instr* mips_disas::_next_coproc_instr()
{
  return new sasm::instr::mips::invalid(_elf, _current_addr);
}

sasm::instr::instr* mips_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

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
