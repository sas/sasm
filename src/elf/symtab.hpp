#include <stdexcept>

namespace sasm { namespace elf {

template<int word_size>
symtab<word_size>::symtab(const sasm::utils::mapped_file& file)
{
  typedef typename sasm::elf::types<word_size>::ehdr  ehdr_type;
  typedef typename sasm::elf::types<word_size>::shdr  shdr_type;
  typedef typename sasm::elf::types<word_size>::sym   sym_type;

  auto ehdr = file.read<ehdr_type>(0);
  off_type symtab_offset;
  int sym_count = -1;
  off_type strtab_offset;

  for (int i = 0; i < ehdr.e_shnum; ++i)
  {
    auto shdr = file.read<shdr_type>(ehdr.e_shoff + i * sizeof (shdr_type));

    if (shdr.sh_type == SHT_SYMTAB)
    {
      symtab_offset = shdr.sh_offset;
      sym_count = shdr.sh_size / shdr.sh_entsize;

      shdr = file.read<shdr_type>(ehdr.e_shoff + shdr.sh_link * sizeof (shdr_type));
      strtab_offset = shdr.sh_offset;

      break;
    }
  }

  for (int i = 0; i < sym_count; ++i)
  {
    auto elf_sym = file.read<sym_type>(symtab_offset + i * sizeof (sym_type));
    auto sym = std::shared_ptr<symbol>(new symbol);

    /* We can use ELF32_ST_TYPE because it is the same macro for ELF64. */
    int type = ELF32_ST_TYPE(elf_sym.st_info);

    /* XXX: We should store every symbol here, not just these types. */
    if (type != STT_NOTYPE && type != STT_OBJECT && type != STT_FUNC && type != STT_COMMON)
      continue;

    /* Easy convertion between STT_* and enum class type. */
    static std::map<int, typename symbol::type> stt_to_enum = {
      { STT_NOTYPE, symbol::type::notype },
      { STT_OBJECT, symbol::type::object },
      { STT_FUNC,   symbol::type::func },
      { STT_COMMON, symbol::type::common },
    };

    for (int j = 0, c; (c = file[strtab_offset + elf_sym.st_name + j]) != 0; ++j)
      sym->name.append(1, c);
    sym->addr = elf_sym.st_value;
    sym->size = elf_sym.st_size;
    sym->type = stt_to_enum[type];

    _name_map[sym->name] = sym;
    _addr_map[sym->addr] = sym;
  }
}

template<int word_size>
auto symtab<word_size>::get_sym(const std::string& name) const -> const symbol&
{
  auto res = _name_map.find(name);

  if (res != _name_map.end())
    return *res->second;
  else
    throw std::out_of_range("sasm::elf::symtab::get_sym");
}

template<int word_size>
auto symtab<word_size>::get_sym(addr_type addr) const -> const symbol&
{
  auto res = _addr_map.find(addr);

  if (res != _addr_map.end())
    return *res->second;
  else
    throw std::out_of_range("symtab::get_sym");
}

template<int word_size>
auto symtab<word_size>::operator[](const std::string& name) const -> const symbol&
{
  return this->get_sym(name);
}

template<int word_size>
auto symtab<word_size>::operator[](addr_type addr) const -> const symbol&
{
  return this->get_sym(addr);
}

template<int word_size>
symtab<word_size>::const_iterator::const_iterator(const symtab<word_size>& symtab, bool end)
{
  if (!end)
    _parent_iter = symtab._addr_map.begin();
  else
    _parent_iter = symtab._addr_map.end();
}

template<int word_size>
auto symtab<word_size>::const_iterator::operator*() const -> const symbol&
{
  return *_parent_iter->second;
}

template<int word_size>
auto symtab<word_size>::const_iterator::operator->() const -> const symbol*
{
  return &(*_parent_iter->second);
}

template<int word_size>
auto symtab<word_size>::const_iterator::operator++() -> const const_iterator&
{
  ++_parent_iter;
  return *this;
}

template<int word_size>
auto symtab<word_size>::const_iterator::operator++(int dummy) -> const const_iterator&
{
  return ++(*this);
}

template<int word_size>
auto symtab<word_size>::const_iterator::operator--() -> const const_iterator&
{
  --_parent_iter;
  return *this;
}

template<int word_size>
auto symtab<word_size>::const_iterator::operator--(int dummy) -> const const_iterator&
{
  return --(*this);
}

template<int word_size>
bool symtab<word_size>::const_iterator::operator==(const const_iterator& rhs) const
{
  return _parent_iter == rhs._parent_iter;
}

template<int word_size>
bool symtab<word_size>::const_iterator::operator!=(const const_iterator& rhs) const
{
  return _parent_iter != rhs._parent_iter;
}

template<int word_size>
auto symtab<word_size>::begin() const -> const_iterator
{
  return const_iterator(*this);
}

template<int word_size>
auto symtab<word_size>::end() const -> const_iterator
{
  return const_iterator(*this, true);
}

}}
