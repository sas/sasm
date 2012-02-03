#include <elf.h>

#include <elf/elf.h>
#include <disas/factory.h>
#include <utils/arg_parse.h>
#include <utils/mapped_file.h>

#include <iostream>

/* XXX: This will move somewhere else. */
void dump_addr(
    std::ostream& out,
    const sasm::disas::disas* disas,
    const sasm::elf::elf& e
  )
{
  try
  {
    auto sym = e.symtab[disas->get_addr()];

    if (sym.type == sasm::elf::symtab::symbol::sym_type::func)
      out << std::endl << sym.name << ":" << std::endl;
  }
  catch (std::out_of_range& e) {}

  out << "  0x" << std::hex << disas->get_addr() << std::dec << ": ";
}


void dump_asm(
    std::ostream& out,
    sasm::disas::disas* disas,
    const sasm::elf::elf& e,
    const std::string& section_name
  )
{
  auto sect = e.sections[section_name];

  out << std::endl << "Section " << sect.name << ":" << std::endl;

  disas->set_addr(sect.vaddr);

  while (disas->get_addr() < sect.vaddr + sect.size)
  {
    dump_addr(out, disas, e);

    auto ins = disas->next_instr();

    ins->dump_asm(out);
    out << std::endl;

    delete ins;
  }
}

int main(int argc, char** argv)
{
  /* Parse args. */
  sasm::utils::arg_parse ap;
  ap.add_options()
    ('f', true, "the file to work on", true)
    ('d', false, "disassemble the file")
    ('j', true, "which section to disassemble")
    ('s', false, "dump the file's symbol table")
  ;
  ap.parse(argc, argv);
  auto ap_res = ap.get_results();


  /* Map the file and create the corresponding elf object. */
  sasm::utils::mapped_file f(ap.get_results()['f'].arg);
  f.map();
  sasm::elf::elf e(f);

  /* Create the disassembler with the elf object. */
  auto disas = sasm::disas::factory(e);

  /* Dump asm. */

  if (ap_res['d'].matched)
  {
    if (ap_res['j'].matched)
      dump_asm(std::cout, disas, e, ap_res['j'].arg);
    else
      for (auto& sect : e.sections)
        if (sect.flags & SHF_EXECINSTR)
          dump_asm(std::cout, disas, e, sect.name);
  }

  /* Dump symtab. */
  if (ap_res['s'].matched)
    for (auto& sym : e.symtab)
      std::cout << "0x" << std::hex << sym.addr << std::dec << ": " << sym.name << std::endl;

  delete disas;
}
