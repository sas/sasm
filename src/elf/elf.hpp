namespace sasm { namespace elf {

template<int word_size>
elf<word_size>::elf(sasm::utils::mapped_file& file)
  : _file(file), _image(file), _symtab(file)
{
}

}}
