all: 	main.exec
main.exec: main.exec.cpp
	clang++ main.exec.cpp -O3 -Wall -Wextra -Wuninitialized -o main.exec
.PHONY: test
test:	$(TARGET)
	@echo "Dummy"
