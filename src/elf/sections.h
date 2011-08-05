#ifndef ELF_SECTIONS_H_
# define ELF_SECTIONS_H_

# include <pervasive.h>
# include <utils/mapped_file.h>

# include <map>
# include <string>

namespace sasm { namespace elf {

class sections
{
public:
  sections(const sasm::utils::mapped_file& file);

  struct section
  {
    std::string name;
    uint64      vaddr;
    uint64      size;
  };

  const section& get_section(const std::string& name) const;
  const section& operator[](const std::string& name) const;

private:
  const sasm::utils::mapped_file& _file;
  std::map<std::string, section>  _sections;
};

}}

# include "sections.hpp"
#endif /* !ELF_SECTIONS_H_ */
