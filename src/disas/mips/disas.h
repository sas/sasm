#ifndef DISAS_MIPS_DISAS_H_
# define DISAS_MIPS_DISAS_H_

# include <disas/disas.h>

namespace sasm { namespace disas {

class mips_disas : public disas
{
public:
  mips_disas(const sasm::elf::elf& elf) : disas(elf) {}
  virtual sasm::instr::instr* next_instr();
};

}}

#endif /* !DISAS_MIPS_H_ */
