#ifndef DISAS_FACTORY_H_
# define DISAS_FACTORY_H_

# include <elf/elf.h>
# include <disas/disas.h>

namespace sasm { namespace disas {

sasm::disas::disas* factory(const sasm::elf::elf& elf);

}}

#endif /* !DISAS_FACTORY_H_ */
