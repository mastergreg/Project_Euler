all: main.exec
main.exec: main.exec.cpp fraction.o
	g++ main.exec.cpp fraction.o -O2 -Wall -Wuninitialized -o main.exec
	fraction: fraction.cpp fraction.h
	g++ fraction.cpp -c -O2

test:
				@echo "Dummy"
