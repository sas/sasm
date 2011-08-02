namespace sasm { namespace elf {

template<int word_size>
elf<word_size>::elf(sasm::utils::mapped_file& file)
  : image(file), symtab(file), _file(file), _ehdr(file.read<ehdr_type>(0))
{
}

template<int word_size>
auto elf<word_size>::get_entry() const -> addr_type
{
  return _ehdr.e_entry;
}

}}
