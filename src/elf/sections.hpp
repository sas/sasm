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

}}
