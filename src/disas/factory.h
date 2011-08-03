#ifndef DISAS_FACTORY_H_
# define DISAS_FACTORY_H_

# include <disas/disas.h>
# include <elf/elf.h>

namespace sasm { namespace disas {

disas* factory(const sasm::elf::elf& elf);

}}

#endif /* !DISAS_FACTORY_H_ */
