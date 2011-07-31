def options(opt):
  opt.load('compiler_cxx')

def configure(cnf):
  cnf.load('compiler_cxx')
  cnf.check(features='cxx cxxprogram', cflags=['-Wall -Wextra -std=c++0x'])

def build(bld):
  bld(features='cxx cxxprogram', source='sasm.cc', target='sasm')
