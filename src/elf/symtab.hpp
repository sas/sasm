#include <stdexcept>

namespace sasm { namespace elf {

inline auto symtab::get_sym(const std::string& name) const -> const symbol&
{
  auto res = _name_map.find(name);

  if (res != _name_map.end())
    return *res->second;
  else
    throw std::out_of_range("sasm::elf::symtab::get_sym");
}

inline auto symtab::get_sym(uint64 addr) const -> const symbol&
{
  auto res = _addr_map.find(addr);

  if (res != _addr_map.end())
    return *res->second;
  else
    throw std::out_of_range("sasm::elf::symtab::get_sym");
}

inline auto symtab::operator[](const std::string& name) const -> const symbol&
{
  return this->get_sym(name);
}

inline auto symtab::operator[](uint64 addr) const -> const symbol&
{
  return this->get_sym(addr);
}

inline symtab::const_iterator::const_iterator(const symtab& symtab, bool end)
{
  if (!end)
    _parent_iter = symtab._addr_map.begin();
  else
    _parent_iter = symtab._addr_map.end();
}

inline auto symtab::const_iterator::operator*() const -> const symbol&
{
  return *_parent_iter->second;
}

inline auto symtab::const_iterator::operator->() const -> const symbol*
{
  return &(*_parent_iter->second);
}

inline auto symtab::const_iterator::operator++() -> const const_iterator&
{
  ++_parent_iter;
  return *this;
}

inline auto symtab::const_iterator::operator++(int dummy) -> const const_iterator&
{
  (void) dummy;
  return ++(*this);
}

inline auto symtab::const_iterator::operator--() -> const const_iterator&
{
  --_parent_iter;
  return *this;
}

inline auto symtab::const_iterator::operator--(int dummy) -> const const_iterator&
{
  (void) dummy;
  return --(*this);
}

inline bool symtab::const_iterator::operator==(const const_iterator& rhs) const
{
  return _parent_iter == rhs._parent_iter;
}

inline bool symtab::const_iterator::operator!=(const const_iterator& rhs) const
{
  return _parent_iter != rhs._parent_iter;
}

inline auto symtab::begin() const -> const_iterator
{
  return const_iterator(*this);
}

inline auto symtab::end() const -> const_iterator
{
  return const_iterator(*this, true);
}

}}
