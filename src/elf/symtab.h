#ifndef ELF_SYMTAB_HH_
# define ELF_SYMTAB_HH_

# include <elf/types.h>
# include <utils/mapped_file.h>

# include <map>
# include <memory>
# include <string>

namespace sasm { namespace elf {

template<int word_size>
class symtab
{
public:
  typedef typename sasm::elf::types<word_size>::addr  addr_type;
  typedef typename sasm::elf::types<word_size>::off   off_type;

  struct symbol
  {
    std::string   name;
    addr_type     addr;
    off_type      size;
  };

public:
  symtab(const sasm::utils::mapped_file& file);

  const symbol& get_sym(const std::string& name) const;
  const symbol& get_sym(addr_type addr) const;

  const symbol& operator[](const std::string& name) const;
  const symbol& operator[](addr_type addr) const;

private:
  std::map<std::string, std::shared_ptr<symbol>> _name_map;
  std::map<addr_type, std::shared_ptr<symbol>> _addr_map;
};

}}

# include "symtab.hpp"
#endif /* !ELF_SYMTAB_HH_ */
