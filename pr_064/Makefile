TARGET = main.exec
CC = clang++
CCFLAGS += -march=native -std=c++11
CCFLAGS += -Wno-variadic-macros
OPT = 3

DEBUG ?= "n"

ifeq ($(DEBUG),"y")
	LDFLAGS += -lfence
	CCFLAGS += -DSET_DEBUG=1
	CCFLAGS += -clang -O0 -Werror -Wall -Wextra -Wuninitialized

	#CCFLAGS += -ggdb -O0 -Wunused-result -Wall -Wextra -Wuninitialized
	#CCFLAGS += -Wall -Wextra -pedantic -Wbad-function-cast \
	#	   -Wstrict-prototypes -Wold-style-definition \
	#	   -Wmissing-prototypes -Wmissing-declarations -Wconversion \
	#	   -Wfloat-equal -Wformat=2 -Winit-self -Winline \
	#	   -Wmissing-include-dirs -Wredundant-decls -Wshadow \
	#	   -Wstack-protector -Wswitch-default -Wswitch-enum \
	#	   -Winvalid-pch -Wstrict-aliasing=2 -Wunknown-pragmas \
	#	   -Wundef -Wunsafe-loop-optimizations -Wpointer-arith \
	#	   -Wcast-qual -Wwrite-strings -Winline -Wvolatile-register-var\
	#	   -Wno-unused-parameter -Wno-variadic-macros
else
	CCFLAGS += -DSET_DEBUG=0
	CCFLAGS += -O$(OPT) -Werror -Wall
endif

CCFILES += $(wildcard *.cpp)
OBJ +=  $(patsubst %.cpp,%.o,$(CCFILES))
DEPENDS += $(wildcard *.h)


all: $(TARGET)

$(TARGET): $(OBJ) $(DEPENDS)
	$(CC) $(OBJ) -o $(TARGET)

%.o:	%.cpp
	$(CC) -c $(CCFLAGS) $< -o $@


.PHONY:	clean all indent tags
clean:
	rm -f $(OBJ) $(TARGET)
indent:
	astyle --style=linux $(CCFILES) $(DEPENDS)
tags:
	ctags -R *

test:	$(TARGET)
	@echo Dummy
