#ifndef INSTR_MIPS_RTYPE_SYSCALL_H_
# define INSTR_MIPS_RTYPE_SYSCALL_H_

# include <pervasive.h>
# include <instr/mips/rtype/instr.h>

namespace sasm { namespace instr { namespace mips { namespace rtype {

struct syscall : public noarg_instr
{
  syscall(const sasm::elf::elf& elf, uint64 addr)
    : noarg_instr(elf, addr)
  { _name = "syscall"; }
  virtual ~syscall() {}
};

}}}}

#endif /* !INSTR_MIPS_RTYPE_SYSCALL_H_ */
