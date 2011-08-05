#ifndef DISAS_FACTORY_H_
# define DISAS_FACTORY_H_

# include <fwd.h>

namespace sasm { namespace disas {

sasm::disas::disas* factory(const sasm::elf::elf& elf);

}}

#endif /* !DISAS_FACTORY_H_ */
