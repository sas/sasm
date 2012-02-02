#ifndef ELF_TYPES_H_
# define ELF_TYPES_H_

#include <elf.h>

namespace sasm { namespace elf {

template<int elf_class>
struct types;

template<>
struct types<ELFCLASS32>
{
  typedef Elf32_Half    half;
  typedef Elf32_Word    word;
  typedef Elf32_Sword   sword;
  typedef Elf32_Xword   xword;
  typedef Elf32_Sxword  sxword;
  typedef Elf32_Addr    addr;
  typedef Elf32_Off     off;
  typedef Elf32_Section section;
  typedef Elf32_Versym  versym;

  typedef Elf32_Ehdr    ehdr;
  typedef Elf32_Shdr    shdr;
  typedef Elf32_Phdr    phdr;

  typedef Elf32_Sym     sym;
  typedef Elf32_Syminfo syminfo;
  typedef Elf32_Rel     rel;
  typedef Elf32_Rela    rela;
  typedef Elf32_Dyn     dyn;
  typedef Elf32_Verdef  verdef;
  typedef Elf32_Verdaux verdaux;
  typedef Elf32_Verneed verneed;;
  typedef Elf32_Vernaux vernaux;
  typedef Elf32_auxv_t  auxv_t;
  typedef Elf32_Nhdr    nhdr;
  typedef Elf32_Move    move;
};

template<>
struct types<ELFCLASS64>
{
  typedef Elf64_Half    half;
  typedef Elf64_Word    word;
  typedef Elf64_Sword   sword;
  typedef Elf64_Xword   xword;
  typedef Elf64_Sxword  sxword;
  typedef Elf64_Addr    addr;
  typedef Elf64_Off     off;
  typedef Elf64_Section section;
  typedef Elf64_Versym  versym;

  typedef Elf64_Ehdr    ehdr;
  typedef Elf64_Shdr    shdr;
  typedef Elf64_Phdr    phdr;

  typedef Elf64_Sym     sym;
  typedef Elf64_Syminfo syminfo;
  typedef Elf64_Rel     rel;
  typedef Elf64_Rela    rela;
  typedef Elf64_Dyn     dyn;
  typedef Elf64_Verdef  verdef;
  typedef Elf64_Verdaux verdaux;
  typedef Elf64_Verneed verneed;;
  typedef Elf64_Vernaux vernaux;
  typedef Elf64_auxv_t  auxv_t;
  typedef Elf64_Nhdr    nhdr;
  typedef Elf64_Move    move;
};

}}

#endif /* !ELF_TYPES_H_ */
