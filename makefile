SUFFIX   = .c
COMPILER = gcc
CFLAGS   = -Wall -O2 -I./include

SRCDIR   = ./src
INCLUDE  = wiringPi ./include/*.o
EXEDIR   = ./bin

SOURCES  = $(wildcard $(SRCDIR)/*$(SUFFIX))
OBJECTS  = $(notdir $(SOURCES:$(SUFFIX)=.o))
TARGETS  = $(notdir $(basename $(SOURCES)))

define MAKEALL
$(1): $(1).o
		$(COMPILER) -L./include -l$(INCLUDE) $(CFLAGS) -o $(EXEDIR)/$(1) $(1).o
		@$(RM) $(1).o
$(1).o:
		$(COMPILER) -L./include -l$(INCLUDE) $(CFLAGS) -c $(SRCDIR)/$(1)$(SUFFIX)
endef

.PHONY: all
all: $(TARGETS)
$(foreach VAR,$(TARGETS),$(eval $(call MAKEALL,$(VAR))))

.PHONY: header
header:
		gcc -lwiringPi -Wall -O2 -c ./include/raspiio.c -o ./include/raspiio.o
		gcc -lwiringPi -Wall -O2 -c ./include/automatic.c -o ./include/automatic.o
		gcc -lwiringPi -Wall -O2 -c ./include/setup.c -o ./include/setup.o

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
		mkdir bin
