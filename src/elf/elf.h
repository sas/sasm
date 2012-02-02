#ifndef ELF_ELF_H_
# define ELF_ELF_H_

# include <ostream>

# include <fwd.h>
# include <pervasive.h>
# include <elf/image.h>
# include <elf/sections.h>
# include <elf/symtab.h>

namespace sasm { namespace elf {

class elf
{
public:
  elf(const sasm::utils::mapped_file& file);
  ~elf();

  sasm::elf::image    image;
  sasm::elf::sections sections;
  sasm::elf::symtab   symtab;
  sasm::disas::disas* disas;

  void dump_symtab(std::ostream& out) const;
  void dump_asm(std::ostream& out) const;
  void dump_asm(std::ostream& out, const std::string& section_name) const;

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
  const sasm::utils::mapped_file& _file;

  void _dump_addr(std::ostream& out) const;
};

}}

#endif /* !ELF_ELF_H_ */
