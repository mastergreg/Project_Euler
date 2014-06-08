all: main.exec
main.exec: main.exec.cpp fraction.o
	clang++ main.exec.cpp fraction.o -O2 -Wall -Wuninitialized -o main.exec
	fraction: fraction.cpp fraction.h
	clang++ fraction.cpp -c -O2

test:	$(TARGET)
				@echo "Dummy"
