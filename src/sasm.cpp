#include <elf/elf.h>
#include <disas/factory.h>
#include <utils/mapped_file.h>

#include <cstdlib>
#include <iostream>

static void usage_die()
{
  extern char *__progname; /* From crt0.o. */
  std::cerr << "usage: " << __progname << " FILE" << std::endl;
  exit(EXIT_FAILURE);
}

#if 0
static void dump_symtab(sasm::elf::elf& elf, std::ostream& out)
{
  for (auto i = elf.symtab.begin(); i != elf.symtab.end(); ++i)
    out << "0x" << std::hex << i->addr << std::dec << ": " << i->name << std::endl;
}
#endif

static void dump_asm(sasm::elf::elf& elf, std::ostream& out)
{
  auto dis = sasm::disas::factory(elf);

  for (int i = 0; i < 10; ++i)
  {
    auto ins = dis->next_instr();
    ins->dump_asm(out);
    delete ins;
  }

  delete dis;
}

int main(int argc, char **argv)
{
  if (argc != 2)
    usage_die();

  sasm::utils::mapped_file f(argv[1]);
  f.map();

  sasm::elf::elf e(f);

  dump_asm(e, std::cout);

  return EXIT_SUCCESS;
}
