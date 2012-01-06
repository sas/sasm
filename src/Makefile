CUR_DIR	:= src

SRCS	:= sasm.cpp			\
	   disas/factory.cpp		\
	   disas/arm/disas.cpp		\
	   disas/mips/disas.cpp		\
	   elf/elf.cpp			\
	   elf/image.cpp		\
	   elf/sections.cpp		\
	   elf/symtab.cpp		\
	   exception/elf.cpp		\
	   exception/os.cpp		\
	   instr/instr.cpp		\
	   instr/invalid.cpp		\
	   instr/arm/instr.cpp		\
	   instr/arm/bx.cpp		\
	   instr/arm/branch.cpp		\
	   instr/arm/data.cpp		\
	   instr/arm/mult.cpp		\
	   instr/arm/swi.cpp		\
	   instr/arm/undef.cpp		\
	   instr/mips/instr.cpp		\
	   instr/mips/itype/instr.cpp	\
	   instr/mips/jtype/instr.cpp	\
	   instr/mips/rtype/instr.cpp	\
	   utils/arg_parse.cpp		\
	   utils/mapped_file.cpp	\

OBJS 	+= $(addprefix $(CUR_DIR)/, $(SRCS:.cpp=.o))
