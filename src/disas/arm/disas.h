#ifndef DISAS_ARM_DISAS_H_
# define DISAS_ARM_DISAS_H_

# include <disas/disas.h>

# include <string>

namespace sasm { namespace disas {

class arm_disas : public disas
{
public:
  arm_disas(const sasm::elf::elf& elf) : disas(elf) {}
  virtual sasm::instr::instr* next_instr();
};

}}

#endif /* !DISAS_ARM_H_ */
