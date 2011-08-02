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

/* Sample functions on elf objects */
template<typename symtab_type>
void dump_symtab(symtab_type symtab, std::ostream& out)
{
  for (auto i = symtab.begin(); i != symtab.end(); ++i)
    out << "0x" << std::hex << i->addr << std::dec << ": " << i->name << std::endl;
}

int main(int argc, char **argv)
{
  if (argc != 2)
    usage_die();

  sasm::utils::mapped_file f(argv[1]);
  f.map();

  sasm::elf::elf<32> e(f);
  sasm::elf::symtab<32> s(f);
  sasm::elf::image<32> i(f);

  dump_symtab(s, std::cout);

  return 0;
}
