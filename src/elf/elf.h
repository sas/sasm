#ifndef ELF_ELF_H_
# define ELF_ELF_H_

# include <ostream>

# include <elf/image.h>
# include <elf/sections.h>
# include <elf/symtab.h>
# include <utils/mapped_file.h>

namespace sasm { namespace elf {

class elf
{
public:
  elf(const sasm::utils::mapped_file& file)
    : image(file), sections(file), symtab(file), _file(file) {}

  sasm::elf::image    image;
  sasm::elf::sections sections;
  sasm::elf::symtab   symtab;

  int get_class() const { return get_class(_file); }
  int get_dataenc() const { return get_dataenc(_file); }
  int get_type() const { return get_type(_file); }
  int get_machine() const { return get_machine(_file); }
  uint64 get_entry() const { return get_entry(_file); }

  static int get_class(const sasm::utils::mapped_file& file);
  static int get_dataenc(const sasm::utils::mapped_file& file);
  static int get_type(const sasm::utils::mapped_file& file);
  static int get_machine(const sasm::utils::mapped_file& file);
  static uint64 get_entry(const sasm::utils::mapped_file& file);

private:
  const sasm::utils::mapped_file& _file;
};

}}

#endif /* !ELF_ELF_H_ */
