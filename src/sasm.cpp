#include <elf/elf.h>
#include <utils/mapped_file.h>

#include <cstdlib>
#include <iostream>

static void usage_die()
{
  extern char *__progname; /* From crt0.o. */
  std::cerr << "usage: " << __progname << " FILE" << std::endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    usage_die();

  sasm::utils::mapped_file f(argv[1]);
  f.map();

  sasm::elf::elf e(f);

  e.dump_asm(std::cout);

  return EXIT_SUCCESS;
}
