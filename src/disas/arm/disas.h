#ifndef DISAS_ARM_DISAS_H_
# define DISAS_ARM_DISAS_H_

# include <fwd.h>
# include <disas/disas.h>

# include <string>

namespace sasm { namespace disas {

class arm_disas : public disas
{
public:
  arm_disas(const sasm::elf::elf& elf) : disas(elf) {}
  virtual ~arm_disas() {}
  virtual sasm::instr::instr* next_instr();

protected:
  const std::string& _get_cond();

  int _cond;
};

}}

#endif /* !DISAS_ARM_H_ */
