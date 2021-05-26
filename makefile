SUFFIX   = .c
COMPILER = cc
CFLAGS   = -Wall -O2

SRCDIR   = ./src
INCLUDE  = wiringPi
EXEDIR   = ./bin

SOURCES  = $(wildcard $(SRCDIR)/*$(SUFFIX))
OBJECTS  = $(notdir $(SOURCES:$(SUFFIX)=.o))
TARGETS  = $(notdir $(basename $(SOURCES)))

define MAKEALL
$(1): $(1).o
		$(COMPILER) -l$(INCLUDE) $(CFLAGS) -o $(EXEDIR)/$(1) $(1).o
		@$(RM) $(1).o
$(1).o:
		$(COMPILER) -l$(INCLUDE) $(CFLAGS) -c $(SRCDIR)/$(1)$(SUFFIX)
endef

.PHONY: all
all: $(TARGETS)
$(foreach VAR,$(TARGETS),$(eval $(call MAKEALL,$(VAR))))

#make clean
.PHONY: clean
clean:
		$(RM) $(EXEDIR)/*

.PHONY: start setup
start: 
		sudo ./bin/piano

setup:
		git clone https://github.com/WiringPi/WiringPi.git
		cd WiringPi && ./build
