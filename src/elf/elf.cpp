#include "elf.h"

#include <disas/disas.h>
#include <disas/factory.h>
#include <elf/sections.h>
#include <elf/types.h>
#include <exception/elf.h>
#include <instr/instr.h>

#include <elf.h>

namespace sasm { namespace elf {

elf::elf(const sasm::utils::mapped_file& file)
  : image(file), sections(file), symtab(file), disas(nullptr), _file(file)
{
  disas = sasm::disas::factory(*this);
}

elf::~elf()
{
  delete disas;
}

void elf::dump_symtab(std::ostream& out) const
{
  for (auto i = symtab.begin(); i != symtab.end(); ++i)
    out << "0x" << std::hex << i->addr << std::dec << ": " << i->name << std::endl;
}

void elf::dump_asm(std::ostream& out) const
{
  for (auto i = sections.begin(); i != sections.end(); ++i)
    if (i->flags & SHF_EXECINSTR)
      dump_asm(out, i->name);
}

void elf::dump_asm(std::ostream& out, const std::string& section_name) const
{
  auto section = sections[section_name];

  out << "Section " << section.name << ":" << std::endl << std::endl;

  disas->set_addr(section.vaddr);

  while (disas->get_addr() < section.vaddr + section.size)
  {
    auto ins = disas->next_instr();

    _dump_addr(out);
    ins->dump_asm(out);
    out << std::endl;

    delete ins;
  }
}

int elf::get_class(const sasm::utils::mapped_file& file)
{
  const byte* begin = &file.read<byte>(0);
  return begin[EI_CLASS];
}

int elf::get_dataenc(const sasm::utils::mapped_file& file)
{
  const byte* begin = &file.read<byte>(0);
  return begin[EI_DATA];
}

template<int elf_class> static int do_get_type(const sasm::utils::mapped_file& file)
{
  typedef typename sasm::elf::types<elf_class>::ehdr ehdr_type;
  auto ehdr = file.read<ehdr_type>(0);
  return ehdr.e_type;
}
int elf::get_type(const sasm::utils::mapped_file& file)
{
  int elf_class = get_class(file);

  if (elf_class == ELFCLASS32)
    return do_get_type<ELFCLASS32>(file);
  else if (elf_class == ELFCLASS64)
    return do_get_type<ELFCLASS64>(file);
  else
    throw sasm::exception::elf(file.get_path(), "invalid ELF file");
}

template<int elf_class> static int do_get_machine(const sasm::utils::mapped_file& file)
{
  typedef typename sasm::elf::types<elf_class>::ehdr ehdr_type;
  auto ehdr = file.read<ehdr_type>(0);
  return ehdr.e_machine;
}
int elf::get_machine(const sasm::utils::mapped_file& file)
{
  int elf_class = get_class(file);

  if (elf_class == ELFCLASS32)
    return do_get_machine<ELFCLASS32>(file);
  else if (elf_class == ELFCLASS64)
    return do_get_machine<ELFCLASS64>(file);
  else
    throw sasm::exception::elf(file.get_path(), "invalid ELF file");
}

template<int elf_class> static uint64 do_get_entry(const sasm::utils::mapped_file& file)
{
  typedef typename sasm::elf::types<elf_class>::ehdr ehdr_type;
  auto ehdr = file.read<ehdr_type>(0);
  return ehdr.e_entry;
}
uint64 elf::get_entry(const sasm::utils::mapped_file& file)
{
  int elf_class = get_class(file);

  if (elf_class == ELFCLASS32)
    return do_get_entry<ELFCLASS32>(file);
  else if (elf_class == ELFCLASS64)
    return do_get_entry<ELFCLASS64>(file);
  else
    throw sasm::exception::elf(file.get_path(), "invalid ELF file");
}

int elf::get_class() const
{
  return get_class(_file);
}

int elf::get_dataenc() const
{
  return get_dataenc(_file);
}

int elf::get_type() const
{
  return get_type(_file);
}

int elf::get_machine() const
{
  return get_machine(_file);
}

uint64 elf::get_entry() const
{
  return get_entry(_file);
}

void elf::_dump_addr(std::ostream& out) const
{
  try
  {
    auto sym = symtab[disas->get_addr()];

    if (sym.type == sasm::elf::symtab::symbol::sym_type::func)
      out << std::endl << sym.name << ":" << std::endl;
  }
  catch (std::out_of_range& e) {}

  out << "  0x" << std::hex << disas->get_addr() << std::dec << ": ";
}

}}
