def options(opt):
  opt.load('compiler_cxx')

def configure(cnf):
  cnf.load('compiler_cxx')
  cnf.check(features='cxx cxxprogram', cflags=['-Wall -Wextra -Weffc++ -std=c++0x'])
  cnf.env.append_value('CXXFLAGS', ['-Wall', '-Wextra', '-std=c++0x', '-g'])

def build(bld):
  s = [
      'src/sasm.cpp',
      'src/disas/factory.cpp',
      'src/disas/arm/disas.cpp',
      'src/disas/mips/disas.cpp',
      'src/elf/elf.cpp',
      'src/elf/image.cpp',
      'src/elf/sections.cpp',
      'src/elf/symtab.cpp',
      'src/exception/elf.cpp',
      'src/exception/os.cpp',
      'src/instr/instr.cpp',
      'src/instr/invalid.cpp',
      'src/instr/arm/instr.cpp',
      'src/instr/arm/bx.cpp',
      'src/instr/arm/branch.cpp',
      'src/instr/arm/data.cpp',
      'src/instr/arm/mult.cpp',
      'src/instr/arm/swi.cpp',
      'src/instr/arm/undef.cpp',
      'src/instr/mips/instr.cpp',
      'src/instr/mips/itype/instr.cpp',
      'src/instr/mips/jtype/instr.cpp',
      'src/instr/mips/rtype/instr.cpp',
      'src/utils/arg_parse.cpp',
      'src/utils/mapped_file.cpp'
  ]
  bld(features='cxx cxxprogram', source=s, target='sasm', includes='src')
