#ifndef ELF_SYMTAB_H_
# define ELF_SYMTAB_H_

# include <map>
# include <memory>
# include <string>

namespace sasm { namespace elf {

class symtab
{
public:
  symtab(const sasm::utils::mapped_file& file);

  struct symbol
  {
    std::string name;
    uint64      addr;
    uint64      size;
    enum class sym_type
    {
      notype,
      object,
      func,
      common,
      tls,
    }           type;
  };

  /*
  ** XXX: get_sym(addr_type addr) and operator[](addr_type addr) only return
  ** *one* symbol corresponding to the given address where there can be
  ** multiple.
  */

  const symbol& get_sym(const std::string& name) const;
  const symbol& get_sym(uint64 addr) const;

  const symbol& operator[](const std::string& name) const;
  const symbol& operator[](uint64 addr) const;

private:
  std::map<std::string, std::shared_ptr<symbol>> _name_map;
  std::multimap<uint64, std::shared_ptr<symbol>> _addr_map;

public:
  class const_iterator
  {
  public:
    const_iterator(const symtab& symtab, bool end = false);

    const symbol& operator*() const;
    const symbol* operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int dummy);
    const_iterator& operator--();
    const_iterator operator--(int dummy);
    bool operator==(const const_iterator& rhs) const;
    bool operator!=(const const_iterator& rhs) const;

  private:
    typename std::multimap<uint64, std::shared_ptr<symbol>>::const_iterator _parent_iter;
  };

  const_iterator begin() const;
  const_iterator end() const;
};

}}

# include "symtab.hpp"
#endif /* !ELF_SYMTAB_H_ */
