#ifndef INSTR_MIPS_RTYPE_SLL_H_
# define INSTR_MIPS_RTYPE_SLL_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct sll : public rd_rt_sa_instr
{
  sll(const sasm::elf::elf& elf, uint64 addr)
    : rd_rt_sa_instr(elf, addr)
  { _name = "sll"; }

  virtual void dump_asm(std::ostream& out) const
  {
    /* nop pseudo instruction. */
    if (_rd_reg == 0 && _rt_reg == 0 && _sa_val == 0)
    {
      out << "nop" << std::endl;
    }
    else
    {
      rd_rt_sa_instr::dump_asm(out);
    }
  }
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SLL_H_ */
