#ifndef ELF_ELF_H_
# define ELF_ELF_H_

# include <pervasive.h>

# include <elf/image.h>
# include <elf/symtab.h>
# include <elf/types.h>
# include <utils/mapped_file.h>

namespace sasm { namespace elf {

class elf
{
public:
  elf(const sasm::utils::mapped_file& file);

  sasm::elf::image  image;
  sasm::elf::symtab symtab;

  static int get_class(const sasm::utils::mapped_file& file);
  static int get_dataenc(const sasm::utils::mapped_file& file);
  static int get_type(const sasm::utils::mapped_file& file);
  static int get_machine(const sasm::utils::mapped_file& file);
  static uint64 get_entry(const sasm::utils::mapped_file& file);

  int get_class() const;
  int get_dataenc() const;
  int get_type() const;
  int get_machine() const;
  uint64 get_entry() const;

private:
  const sasm::utils::mapped_file _file;
};

}}

#endif /* !ELF_ELF_H_ */
