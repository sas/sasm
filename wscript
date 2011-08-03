def options(opt):
  opt.load('compiler_cxx')

def configure(cnf):
  cnf.load('compiler_cxx')
  cnf.check(features='cxx cxxprogram', cflags=['-Wall -Wextra -std=c++0x'])
  cnf.env.append_value('CXXFLAGS', ['-Wall', '-Wextra', '-std=c++0x'])

def build(bld):
  s = [
      'src/sasm.cpp',
      'src/disas/disas.cpp',
      'src/disas/factory.cpp',
      'src/disas/mips/disas.cpp',
      'src/elf/elf.cpp',
      'src/elf/image.cpp',
      'src/elf/symtab.cpp',
      'src/exception/elf.cpp',
      'src/exception/os.cpp',
      'src/instr/instr.cpp',
      'src/instr/mips/invalid.cpp',
      'src/instr/mips/nop.cpp',
      'src/instr/mips/rtype/add.cpp',
      'src/instr/mips/rtype/instr.cpp',
      'src/utils/mapped_file.cpp'
  ]
  bld(features='cxx cxxprogram', source=s, target='sasm', includes='src')
