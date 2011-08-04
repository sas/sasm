#ifndef INSTR_MIPS_RTYPE_ADDU_H_
# define INSTR_MIPS_RTYPE_ADDU_H_

# include <pervasive.h>
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
    {
      _dump_addr(out);
      out << "move ";
      _dump_rd_reg(out);
      out << ", ";
      _dump_rs_reg(out);
      out << std::endl;
    }
    else
    {
      rd_rs_rt_instr::dump_asm(out);
    }
  }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_ADDU_H_ */
