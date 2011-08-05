#include "disas.h"

#include <pervasive.h>
#include <instr/mips/invalid.h>
#include <instr/mips/itype/addi.h>
#include <instr/mips/itype/addiu.h>
#include <instr/mips/itype/andi.h>
#include <instr/mips/itype/beq.h>
#include <instr/mips/itype/bgez.h>
#include <instr/mips/itype/bgtz.h>
#include <instr/mips/itype/blez.h>
#include <instr/mips/itype/bltz.h>
#include <instr/mips/itype/bne.h>
#include <instr/mips/itype/lb.h>
#include <instr/mips/itype/lbu.h>
#include <instr/mips/itype/lh.h>
#include <instr/mips/itype/lhu.h>
#include <instr/mips/itype/lui.h>
#include <instr/mips/itype/lw.h>
#include <instr/mips/itype/ori.h>
#include <instr/mips/itype/sb.h>
#include <instr/mips/itype/sh.h>
#include <instr/mips/itype/slti.h>
#include <instr/mips/itype/sltiu.h>
#include <instr/mips/itype/sw.h>
#include <instr/mips/itype/xori.h>
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

namespace sasm { namespace disas {

static sasm::instr::instr* next_rtype_instr(const sasm::elf::elf& elf, uint64 current_addr)
{
  auto next = elf.image.read<uint32>(current_addr);

  switch (MIPS_RTYPE_FUNCTION(next))
  {
    case 0x00: return new sasm::instr::mips::rtype::sll(elf, current_addr);
    case 0x02: return new sasm::instr::mips::rtype::srl(elf, current_addr);
    case 0x03: return new sasm::instr::mips::rtype::sra(elf, current_addr);
    case 0x04: return new sasm::instr::mips::rtype::sllv(elf, current_addr);
    case 0x06: return new sasm::instr::mips::rtype::srlv(elf, current_addr);
    case 0x07: return new sasm::instr::mips::rtype::srav(elf, current_addr);
    case 0x08: return new sasm::instr::mips::rtype::jr(elf, current_addr);
    case 0x09: return new sasm::instr::mips::rtype::jalr(elf, current_addr);
    case 0x0c: return new sasm::instr::mips::rtype::syscall(elf, current_addr);
    case 0x0d: return new sasm::instr::mips::rtype::break_(elf, current_addr);
    case 0x10: return new sasm::instr::mips::rtype::mfhi(elf, current_addr);
    case 0x11: return new sasm::instr::mips::rtype::mthi(elf, current_addr);
    case 0x12: return new sasm::instr::mips::rtype::mflo(elf, current_addr);
    case 0x13: return new sasm::instr::mips::rtype::mtlo(elf, current_addr);
    case 0x18: return new sasm::instr::mips::rtype::mult(elf, current_addr);
    case 0x19: return new sasm::instr::mips::rtype::multu(elf, current_addr);
    case 0x1a: return new sasm::instr::mips::rtype::div(elf, current_addr);
    case 0x1b: return new sasm::instr::mips::rtype::divu(elf, current_addr);
    case 0x20: return new sasm::instr::mips::rtype::add(elf, current_addr);
    case 0x21: return new sasm::instr::mips::rtype::addu(elf, current_addr);
    case 0x22: return new sasm::instr::mips::rtype::sub(elf, current_addr);
    case 0x23: return new sasm::instr::mips::rtype::subu(elf, current_addr);
    case 0x24: return new sasm::instr::mips::rtype::and_(elf, current_addr);
    case 0x25: return new sasm::instr::mips::rtype::or_(elf, current_addr);
    case 0x26: return new sasm::instr::mips::rtype::xor_(elf, current_addr);
    case 0x27: return new sasm::instr::mips::rtype::nor(elf, current_addr);
    case 0x2a: return new sasm::instr::mips::rtype::slt(elf, current_addr);
    case 0x2b: return new sasm::instr::mips::rtype::sltu(elf, current_addr);
    default: return new sasm::instr::mips::invalid(elf, current_addr);
  }
}

sasm::instr::instr* mips_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  switch (MIPS_INSTR_OPCODE(next))
  {
    case 0x00: res = next_rtype_instr(_elf, _current_addr);                     break;
    case 0x01:
               if (MIPS_ITYPE_EXTRACT_RT(next) == 0x00)
                 res = new sasm::instr::mips::itype::bltz(_elf, _current_addr);
               else if (MIPS_ITYPE_EXTRACT_RT(next) == 0x01)
                 res = new sasm::instr::mips::itype::bgez(_elf, _current_addr);
               else
                 res = new sasm::instr::mips::invalid(_elf, _current_addr);
               break;
    case 0x02: res = new sasm::instr::mips::jtype::j(_elf, _current_addr);      break;
    case 0x03: res = new sasm::instr::mips::jtype::jal(_elf, _current_addr);    break;
    case 0x04: res = new sasm::instr::mips::itype::beq(_elf, _current_addr);    break;
    case 0x05: res = new sasm::instr::mips::itype::bne(_elf, _current_addr);    break;
    case 0x06:
               if (MIPS_ITYPE_EXTRACT_RT(next) == 0x00)
                 res = new sasm::instr::mips::itype::blez(_elf, _current_addr);
               else
                 res = new sasm::instr::mips::invalid(_elf, _current_addr);
               break;
    case 0x07:
               if (MIPS_ITYPE_EXTRACT_RT(next) == 0x00)
                 res = new sasm::instr::mips::itype::bgtz(_elf, _current_addr);
               else
                 res = new sasm::instr::mips::invalid(_elf, _current_addr);
               break;
    case 0x08: res = new sasm::instr::mips::itype::addi(_elf, _current_addr);   break;
    case 0x09: res = new sasm::instr::mips::itype::addiu(_elf, _current_addr);  break;
    case 0x0a: res = new sasm::instr::mips::itype::slti(_elf, _current_addr);   break;
    case 0x0b: res = new sasm::instr::mips::itype::sltiu(_elf, _current_addr);  break;
    case 0x0c: res = new sasm::instr::mips::itype::andi(_elf, _current_addr);   break;
    case 0x0d: res = new sasm::instr::mips::itype::ori(_elf, _current_addr);    break;
    case 0x0e: res = new sasm::instr::mips::itype::xori(_elf, _current_addr);   break;
    case 0x0f: res = new sasm::instr::mips::itype::lui(_elf, _current_addr);    break;
    case 0x20: res = new sasm::instr::mips::itype::lb(_elf, _current_addr);     break;
    case 0x21: res = new sasm::instr::mips::itype::lh(_elf, _current_addr);     break;
    case 0x23: res = new sasm::instr::mips::itype::lw(_elf, _current_addr);     break;
    case 0x24: res = new sasm::instr::mips::itype::lbu(_elf, _current_addr);    break;
    case 0x25: res = new sasm::instr::mips::itype::lhu(_elf, _current_addr);    break;
    case 0x28: res = new sasm::instr::mips::itype::sb(_elf, _current_addr);     break;
    case 0x29: res = new sasm::instr::mips::itype::sh(_elf, _current_addr);     break;
    case 0x2b: res = new sasm::instr::mips::itype::sw(_elf, _current_addr);     break;
    default: res = new sasm::instr::mips::invalid(_elf, _current_addr);
  }

  _current_addr += 4; // Fixed size instructions

  return res;
}

}}
