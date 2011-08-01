#include <elf/elf.h>
#include <utils/mapped_file.h>

#include <errno.h>
#include <iostream>

void usage()
{
  extern char *__progname; /* From crt0.o. */
  std::cerr << "usage: " << __progname << " FILE" << std::endl;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    usage();
    return 1;
  }

  sasm::utils::mapped_file f(argv[1]);
  f.map();

  sasm::elf::elf<32> e(f);

  return 0;
}
