all: main.exec

main.exec: main.exec.cpp
	clang++ main.exec.cpp -o main.exec -lm -O3 -Wall -Wuninitialized
test:	$(TARGET)
				@echo "Dummy"
