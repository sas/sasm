#ifndef ELF_SECTIONS_H_
# define ELF_SECTIONS_H_

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
    int         flags;
  };

  const section& get_section(const std::string& name) const;
  const section& operator[](const std::string& name) const;

private:
  const sasm::utils::mapped_file& _file;
  std::map<std::string, section>  _sections;

public:
  class const_iterator
  {
  public:
    const_iterator(const sections& sections, bool end = false);

    const section& operator*() const;
    const section* operator->() const;
    const_iterator& operator++();
    const_iterator operator++(int dummy);
    const_iterator& operator--();
    const_iterator operator--(int dummy);
    bool operator==(const const_iterator& rhs) const;
    bool operator!=(const const_iterator& rhs) const;

  private:
    typename std::map<std::string, section>::const_iterator _parent_iter;
  };

  const_iterator begin() const;
  const_iterator end() const;
};

}}

# include "sections.hpp"
#endif /* !ELF_SECTIONS_H_ */
