#ifndef ELF_INFO_H_
# define ELF_INFO_H_

# include <utils/mapped_file.h>

namespace sasm { namespace elf {

int get_class(const sasm::utils::mapped_file& file);

}}

#endif /* !ELF_INFO_H_ */
