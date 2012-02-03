#ifndef INSTR_MIPS_RTYPE_ADDU_H_
# define INSTR_MIPS_RTYPE_ADDU_H_

# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct addu : public rd_rs_rt_instr
{
  addu(const sasm::elf::elf& elf, uint64 addr)
    : rd_rs_rt_instr(elf, addr)
  { _name = "addu"; }

  virtual void dump_asm(std::ostream& out) const
  {
    /* move pseudo instruction. */
    if (_rt_reg == 0)
      out << "move " << _get_reg_name(_rd_reg) << ", " << _get_reg_name(_rs_reg);
    else
      rd_rs_rt_instr::dump_asm(out);
  }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_ADDU_H_ */
