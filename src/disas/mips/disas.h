#ifndef DISAS_MIPS_DISAS_H_
# define DISAS_MIPS_DISAS_H_

# include <disas/disas.h>
# include <instr/instr.h>

namespace sasm { namespace disas {

class mips_disas : public disas
{
public:
  mips_disas(const sasm::elf::elf& elf);
  virtual sasm::instr::instr* next_instr();
private:
  sasm::instr::instr* _next_rtype_instr();
  sasm::instr::instr* _next_itype_instr();
  sasm::instr::instr* _next_jtype_instr();
  sasm::instr::instr* _next_coproc_instr();
};

}}

#endif /* !DISAS_MIPS_H_ */
