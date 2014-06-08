TARGET = main.exec
CXX = clang++
CXXFLAGS += -march=native -std=c++11
CXXFLAGS += -Wno-variadic-macros
OPT = 3

DEBUG ?= "n"

ifeq ($(DEBUG),"y")
	LDFLAGS += -lfence
	CXXFLAGS += -DSET_DEBUG=1
	CXXFLAGS += -clang -O0 -Werror -Wall -Wextra -Wuninitialized

	#CXXFLAGS += -ggdb -O0 -Wunused-result -Wall -Wextra -Wuninitialized
	#CXXFLAGS += -Wall -Wextra -pedantic -Wbad-function-cast \
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
	CXXFLAGS += -DSET_DEBUG=0
	CXXFLAGS += -O$(OPT) -Werror -Wall
endif

CXXFILES += $(wildcard *.cpp)
OBJ +=  $(patsubst %.cpp,%.o,$(CXXFILES))
DEPENDS += $(wildcard *.h)


all: $(TARGET)

$(TARGET): $(OBJ) $(DEPENDS)
	$(CXX) $(OBJ) -o $(TARGET)

%.o:	%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@


.PHONY:	clean all indent tags
clean:
	rm -f $(OBJ) $(TARGET)
indent:
	astyle --style=linux $(CXXFILES) $(DEPENDS)
tags:
	ctags -R *
test:	$(TARGET)
	./$(TARGET) test
