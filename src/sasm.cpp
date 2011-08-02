#include <elf/elf.h>
#include <utils/mapped_file.h>

#include <cstdlib>
#include <iostream>

void usage_die()
{
  extern char *__progname; /* From crt0.o. */
  std::cerr << "usage: " << __progname << " FILE" << std::endl;
  exit(1);
}


template<typename elf_type>
void dump_symtab(elf_type elf, std::ostream& out)
{
  for (auto i = elf.symtab.begin(); i != elf.symtab.end(); ++i)
    out << "0x" << std::hex << i->addr << std::dec << ": " << i->name << std::endl;
}

template<typename elf_type>
void dump_entry(elf_type elf, std::ostream& out)
{
  out << "0x" << std::hex << elf.get_entry() << std::dec << std::endl;
}


int main(int argc, char **argv)
{
  if (argc != 2)
    usage_die();

  sasm::utils::mapped_file f(argv[1]);
  f.map();

  sasm::elf::elf<32> e(f);

  dump_entry(e, std::cout);

  return 0;
}
