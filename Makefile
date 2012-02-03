BUILDDIR		?= .
ROOT			?= .
include			$(BUILDDIR)/config.mk

# verbose ?
ifeq ($(VERBOSE), 1)
	MAKEFLAGS	=
	echo		=
else
	MAKEFLAGS	= --silent --no-print-directory
	echo		= echo -e $(1)
endif

TARGET			:= sasm

OBJS			:=
SUBDIRS			:= src
include			$(foreach subdir, $(SUBDIRS), $(ROOT)/$(subdir)/Makefile)
DEPS			:= $(OBJS:.o=.d)

# required flags
CXXFLAGS		+= -Wall -Wextra -std=c++0x
CXXFLAGS		+= -include $(ROOT)/src/pervasive.h
CXXFLAGS		+= -I $(ROOT)/src -include $(ROOT)/src/pervasive.h
MAKEFLAGS		+= --no-builtin-rules --no-builtin-variables
MAKEFLAGS		+= --warn-undefined-variables
.SUFFIXES:		.cpp .o .h .S

.PHONY: clean distclean rebuild

all: $(TARGET)

$(TARGET): $(OBJS)
	$(call echo, "LD\t$@")
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(call echo, "CXX\t$<")
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	$(call echo, "RM\t$(OBJS)")
	$(call echo, "RM\t$(DEPS)")
	rm -f $(OBJS)
	rm -f $(DEPS)

distclean: clean
	$(call echo, "RM\t$(TARGET)")
	rm -f $(TARGET)

rebuild: distclean all

-include $(DEPS)
