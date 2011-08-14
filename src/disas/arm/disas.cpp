#include "disas.h"

#include <pervasive.h>
#include <instr/invalid.h>
#include <instr/arm/branch.h>
#include <instr/arm/bx.h>
#include <instr/arm/data.h>
#include <instr/arm/mult.h>
#include <instr/arm/swi.h>
#include <instr/arm/undef.h>

#include <vector>

#define ARM_INSTR_DATA_MASK   0x0c000000
#define ARM_INSTR_DATA        0x00000000
#define ARM_INSTR_MULT_MASK   0x0f0000f0
#define ARM_INSTR_MULT        0x00000090
#define ARM_INSTR_SWAP_MASK   0x01000090
#define ARM_INSTR_SWAP        0x0fb00ff0
#define ARM_INSTR_BX_MASK     0x0ffffff0
#define ARM_INSTR_BX          0x012fff10
#define ARM_INSTR_HDTREG_MASK 0x0e400f90
#define ARM_INSTR_HDTREG      0x00000090
#define ARM_INSTR_HDTIMM_MASK 0x01400090
#define ARM_INSTR_HDTIMM      0x00400090
#define ARM_INSTR_SDT_MASK    0x0c000000
#define ARM_INSTR_SDT         0x04000000
#define ARM_INSTR_UNDEF_MASK  0x0e000010
#define ARM_INSTR_UNDEF       0x06000010
#define ARM_INSTR_BDT_MASK    0x0e000000
#define ARM_INSTR_BDT         0x08000000
#define ARM_INSTR_BRANCH_MASK 0x0e000000
#define ARM_INSTR_BRANCH      0x0a000000
#define ARM_INSTR_CDT_MASK    0x0e000000
#define ARM_INSTR_CDT         0x0c000000
#define ARM_INSTR_CDO_MASK    0x0f000010
#define ARM_INSTR_CDO         0x0e000000
#define ARM_INSTR_CRT_MASK    0x0f000010
#define ARM_INSTR_CRT         0x0e000010
#define ARM_INSTR_SWI_MASK    0x0f000000
#define ARM_INSTR_SWI         0x0f000000

#define ARM_INSTR_IS_A(Instr, Type) \
  ((Instr & ARM_INSTR_ ## Type ## _MASK) == ARM_INSTR_ ## Type)

#include <iostream>

namespace sasm { namespace disas {

sasm::instr::instr* arm_disas::next_instr()
{
  auto next = _elf.image.read<uint32>(_current_addr);
  sasm::instr::instr* res;

  /* Order is important here, we have to put the most specific masks first. */
  if (ARM_INSTR_IS_A(next, BX))
    res = new sasm::instr::arm::bx(_elf, _current_addr);
  else if (ARM_INSTR_IS_A(next, SWI))
    res = new sasm::instr::arm::swi(_elf, _current_addr);
  else if (ARM_INSTR_IS_A(next, MULT))
    res = new sasm::instr::arm::mult(_elf, _current_addr);
  else if (ARM_INSTR_IS_A(next, UNDEF))
    res = new sasm::instr::arm::undef(_elf, _current_addr);
  else if (ARM_INSTR_IS_A(next, BRANCH))
    res = new sasm::instr::arm::branch(_elf, _current_addr);
  else if (ARM_INSTR_IS_A(next, DATA))
    res = new sasm::instr::arm::data(_elf, _current_addr);
  else
    res = new sasm::instr::invalid(_elf, _current_addr);

  _current_addr += 4; // Fixed size instructions

  return res;
}

}}
