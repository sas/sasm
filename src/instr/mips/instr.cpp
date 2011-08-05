#include "instr.h"

#include <map>
#include <sstream>

namespace sasm { namespace instr { namespace mips {

mips_instr::mips_instr(const sasm::elf::elf& elf, uint64 addr)
  : instr(elf, addr)
{
}

const std::string& mips_instr::_get_reg_name(int reg)
{
  static std::map<int, std::string> reg_to_name = {
    { 0,  "zero" }, { 1,  "at" }, { 2,  "v0" }, { 3,  "v1" },
    { 4,  "a0" },   { 5,  "a1" }, { 6,  "a2" }, { 7,  "a3" },
    { 8,  "t0" },   { 9,  "t1" }, { 10, "t2" }, { 11, "t3" },
    { 12, "t4" },   { 13, "t5" }, { 14, "t6" }, { 15, "t7" },
    { 16, "s0" },   { 17, "s1" }, { 18, "s2" }, { 19, "s3" },
    { 20, "s4" },   { 21, "s5" }, { 22, "s6" }, { 23, "s7" },
    { 24, "t8" },   { 25, "t9" }, { 26, "k0" }, { 27, "k1" },
    { 28, "gp" },   { 29, "sp" }, { 30, "sp" }, { 31, "ra" },
  };

  return reg_to_name[reg];
}

/*
** XXX: For the two following functions, we should return the target symbol name
** if possible.
*/

std::string mips_instr::_get_rela_addr(sint32 offset) const
{
  std::ostringstream os;

  os << "0x" << std::hex << _addr + offset << std::dec;

  return os.str();
}

std::string mips_instr::_get_abs_addr(uint64 addr) const
{
  std::ostringstream os;

  os << "0x" << std::hex << addr << std::dec;

  return os.str();
}

}}}