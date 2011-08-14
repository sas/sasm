#include <stdexcept>

namespace sasm { namespace elf {

inline auto sections::get_section(const std::string& name) const -> const section&
{
  auto res = _sections.find(name);

  if (res != _sections.end())
    return res->second;
  else
    throw std::out_of_range("sasm::elf::sections::get_section");
}

inline auto sections::operator[](const std::string& name) const -> const section&
{
  return this->get_section(name);
}

inline sections::const_iterator::const_iterator(const sections& sections, bool end)
  : _parent_iter(sections._sections.begin())
{
  if (end)
    _parent_iter = sections._sections.end();
}

inline auto sections::const_iterator::operator*() const -> const section&
{
  return _parent_iter->second;
}

inline auto sections::const_iterator::operator->() const -> const section*
{
  return &(_parent_iter->second);
}

inline auto sections::const_iterator::operator++() -> const_iterator&
{
  ++_parent_iter;
  return *this;
}

inline auto sections::const_iterator::operator++(int dummy) -> const_iterator
{
  (void) dummy;
  const_iterator res = *this;
  ++(*this);
  return res;
}

inline auto sections::const_iterator::operator--() -> const_iterator&
{
  --_parent_iter;
  return *this;
}

inline auto sections::const_iterator::operator--(int dummy) -> const_iterator
{
  (void) dummy;
  const_iterator res = *this;
  --(*this);
  return res;
}

inline bool sections::const_iterator::operator==(const const_iterator& rhs) const
{
  return _parent_iter == rhs._parent_iter;
}

inline bool sections::const_iterator::operator!=(const const_iterator& rhs) const
{
  return _parent_iter != rhs._parent_iter;
}

inline auto sections::begin() const -> const_iterator
{
  return const_iterator(*this);
}

inline auto sections::end() const -> const_iterator
{
  return const_iterator(*this, true);
}

}}
