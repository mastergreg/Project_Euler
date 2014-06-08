all: main.exec
main.exec: main.exec.c
	clang++ main.exec.c -O2 -o main.exec -Wall -Wextra -Wuninitialized
test:	$(TARGET)
	@echo "Dummy"
