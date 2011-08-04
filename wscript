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
      'src/instr/mips/itype/instr.cpp',
      'src/instr/mips/jtype/instr.cpp',
      'src/instr/mips/jtype/j.cpp',
      'src/instr/mips/jtype/jal.cpp',
      'src/instr/mips/rtype/add.cpp',
      'src/instr/mips/rtype/addu.cpp',
      'src/instr/mips/rtype/and.cpp',
      'src/instr/mips/rtype/break.cpp',
      'src/instr/mips/rtype/div.cpp',
      'src/instr/mips/rtype/divu.cpp',
      'src/instr/mips/rtype/instr.cpp',
      'src/instr/mips/rtype/jalr.cpp',
      'src/instr/mips/rtype/jr.cpp',
      'src/instr/mips/rtype/mfhi.cpp',
      'src/instr/mips/rtype/mflo.cpp',
      'src/instr/mips/rtype/mthi.cpp',
      'src/instr/mips/rtype/mtlo.cpp',
      'src/instr/mips/rtype/mult.cpp',
      'src/instr/mips/rtype/multu.cpp',
      'src/instr/mips/rtype/nor.cpp',
      'src/instr/mips/rtype/or.cpp',
      'src/instr/mips/rtype/sll.cpp',
      'src/instr/mips/rtype/sllv.cpp',
      'src/instr/mips/rtype/slt.cpp',
      'src/instr/mips/rtype/sltu.cpp',
      'src/instr/mips/rtype/sra.cpp',
      'src/instr/mips/rtype/srav.cpp',
      'src/instr/mips/rtype/srl.cpp',
      'src/instr/mips/rtype/srlv.cpp',
      'src/instr/mips/rtype/sub.cpp',
      'src/instr/mips/rtype/subu.cpp',
      'src/instr/mips/rtype/syscall.cpp',
      'src/instr/mips/rtype/xor.cpp',
      'src/utils/mapped_file.cpp'
  ]
  bld(features='cxx cxxprogram', source=s, target='sasm', includes='src')
