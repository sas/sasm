namespace sasm { namespace elf {

template<int word_size>
symtab<word_size>::symtab(const sasm::utils::mapped_file& file)
  : _file(file), _symtab_exists(false)
{
  auto ehdr = _file.read<ehdr_type>(0);

  for (int i = 0; i < ehdr.e_shnum; ++i)
  {
    auto shdr = _file.read<shdr_type>(ehdr.e_shoff + i * sizeof (shdr_type));

    if (shdr.sh_type == SHT_SYMTAB)
    {
      _symtab_offset = shdr.sh_offset;
      _sym_count = shdr.sh_size / shdr.sh_entsize;
      shdr = _file.read<shdr_type>(ehdr.e_shoff + shdr.sh_link * sizeof (shdr_type));
      _strtab_offset = shdr.sh_offset;
      _strtab_size = shdr.sh_size;
      _symtab_exists = true;
      break;
    }
  }
}

template<int word_size>
auto symtab<word_size>::get_addr(std::string& name) const -> addr_type
{
  auto cached_value = this->_cache.right.find(name);
  if (cached_value != this->_cache.right.end())
    return cached_value->second;
}

template<int word_size>
std::string symtab<word_size>::get_name(addr_type addr) const
{
  auto cached_value = this->_cache.left.find(addr);
  if (cached_value != this->_cache.left.end())
    return cached_value->second;

  return 0;
}

template<int word_size>
auto symtab<word_size>::operator[](std::string& name) const -> addr_type
{
  return this->get_addr(name);
}

template<int word_size>
std::string symtab<word_size>::operator[](addr_type addr) const
{
  return this->get_name(addr);
}

}}
