#include <elf/elf.h>
#include <utils/arg_parse.h>
#include <utils/mapped_file.h>

#include <iostream>

int main(int argc, char** argv)
{
  sasm::utils::arg_parse ap;

  ap.add_options()
    ('f', true, "the file to work on", true)
    ('d', false, "disassemble the file")
    ('j', true, "which section to disassemble")
    ('s', false, "dump the file's symbol table")
  ;

  ap.parse(argc, argv);

  auto ap_res = ap.get_results();

  sasm::utils::mapped_file f(ap.get_results()['f'].arg);
  f.map();

  sasm::elf::elf e(f);

  if (ap_res['d'].matched)
  {
    if (ap_res['j'].matched)
      e.dump_asm(std::cout, ap_res['j'].arg);
    else
      e.dump_asm(std::cout);
  }

  if (ap_res['s'].matched)
    e.dump_symtab(std::cout);

  return EXIT_SUCCESS;
}
