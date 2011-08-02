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
    enum class    type
    {
      notype,
      object,
      func,
      common,
      tls,
    }             type;
  };

public:
  symtab(const sasm::utils::mapped_file& file);

  /*
  ** XXX: get_sym(addr_type addr) and operator[](addr_type addr) only return
  ** *one* symbol corresponding to the given address.
  */

  const symbol& get_sym(const std::string& name) const;
  const symbol& get_sym(addr_type addr) const;

  const symbol& operator[](const std::string& name) const;
  const symbol& operator[](addr_type addr) const;

private:
  std::map<std::string, std::shared_ptr<symbol>> _name_map;
  std::multimap<addr_type, std::shared_ptr<symbol>> _addr_map;

public:
  class const_iterator
  {
  public:
    const_iterator(const symtab<word_size>& symtab, bool end = false);

    const symbol& operator*() const;
    const symbol* operator->() const;
    const const_iterator& operator++();
    const const_iterator& operator++(int dummy);
    const const_iterator& operator--();
    const const_iterator& operator--(int dummy);
    bool operator==(const const_iterator& rhs) const;
    bool operator!=(const const_iterator& rhs) const;

  private:
    typename std::multimap<addr_type, std::shared_ptr<symbol>>::const_iterator _parent_iter;
  };

  const_iterator begin() const;
  const_iterator end() const;
};

}}

# include "symtab.hpp"
#endif /* !ELF_SYMTAB_HH_ */
