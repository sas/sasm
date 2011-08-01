#ifndef ELF_SYMTAB_HH_
# define ELF_SYMTAB_HH_

# include <elf/types.h>
# include <utils/mapped_file.h>

# include <boost/bimap.hpp>
# include <elf.h>
# include <string>

namespace sasm { namespace elf {

template<int word_size>
class symtab
{
public:
  typedef typename sasm::elf::types<word_size>::addr  addr_type;
  typedef typename sasm::elf::types<word_size>::off   off_type;
  typedef typename sasm::elf::types<word_size>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<word_size>::shdr  shdr_type;

public:
  symtab(const sasm::utils::mapped_file& file);

  addr_type get_addr(std::string& name) const;
  std::string get_name(addr_type addr) const;

  addr_type operator[](std::string& name) const;
  std::string operator[](addr_type addr) const;

private:
  const sasm::utils::mapped_file& _file;
  bool                            _symtab_exists;

  off_type  _symtab_offset;
  int       _sym_count;
  off_type  _strtab_offset;
  int       _strtab_size;

  typedef boost::bimap<addr_type, std::string>  bm_type;
  bm_type                                       _cache;
};

}}

# include "symtab.hpp"
#endif /* !ELF_SYMTAB_HH_ */
