#TO BE USED WITH LATEX
#TARGET =
#CC = xelatex
#CCFLAGS = -shell-escape
#
#all: $(TARGET).pdf
#
#%.pdf:	%.tex title/* files/*
#	$(CC) $(CCFLAGS) $<
#
#
#.PHONY:	clean all spell
#clean:
#	rm -f $(TARGET).{pdf,log,aux,pyg}
#
#spell:
#	aspell -l el_gr --ignore-case=true -c $(TARGET).tex
#TO BE USED WITH LATEX
TARGET = main.exec
CC = gcc
CCFLAGS +=
LDFLAGS += -lm
OPT = 3


CCFLAGS += -O$(OPT) -Wextra -Wall

CCFILES += $(wildcard *.c)
OBJ +=  $(patsubst %.c,%.o,$(CCFILES))
DEPENDS += $(wildcard *.h)


all: $(TARGET)

$(TARGET): $(OBJ) $(DEPENDS)
	$(CC) $(LDFLAGS) $(OBJ) -o $(TARGET)

%.o:	%.c
	$(CC) -c $(CCFLAGS) $< -o $@


.PHONY:	clean all indent
clean:
	rm -f $(OBJ) $(TARGET)
indent:
	astyle --style=bsd $(CCFILES)
test:	$(TARGET)
	@echo "Dummy"
