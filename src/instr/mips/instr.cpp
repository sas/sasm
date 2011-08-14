#include "instr.h"

#include <map>

namespace sasm { namespace instr { namespace mips {

const std::string& mips_instr::_get_reg_name(int reg)
{
  static std::map<int, std::string> reg_to_str = {
    { 0,  "zero" }, { 1,  "at" }, { 2,  "v0" }, { 3,  "v1" },
    { 4,  "a0" },   { 5,  "a1" }, { 6,  "a2" }, { 7,  "a3" },
    { 8,  "t0" },   { 9,  "t1" }, { 10, "t2" }, { 11, "t3" },
    { 12, "t4" },   { 13, "t5" }, { 14, "t6" }, { 15, "t7" },
    { 16, "s0" },   { 17, "s1" }, { 18, "s2" }, { 19, "s3" },
    { 20, "s4" },   { 21, "s5" }, { 22, "s6" }, { 23, "s7" },
    { 24, "t8" },   { 25, "t9" }, { 26, "k0" }, { 27, "k1" },
    { 28, "gp" },   { 29, "sp" }, { 30, "fp" }, { 31, "ra" },
  };

  return reg_to_str[reg];
}

}}}
