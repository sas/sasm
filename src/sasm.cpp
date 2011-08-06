#include <elf/elf.h>
#include <utils/arg_parse.h>
#include <utils/mapped_file.h>

#include <iostream>

int main(int argc, char **argv)
{
  sasm::utils::arg_parse ap;

  ap.add_options()
    ('f', true, "the file to work on", true)
    ('d', false, "disassemble the file")
    ('s', false, "dump the file's symbol table")
  ;

  ap.parse(argc, argv);

  sasm::utils::mapped_file f(ap.get_results()['f'].arg);
  f.map();

  sasm::elf::elf e(f);

  if (ap.get_results()['d'].matched)
    e.dump_asm(std::cout);
  if (ap.get_results()['s'].matched)
    e.dump_symtab(std::cout);

  return EXIT_SUCCESS;
}
