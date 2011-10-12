all: main
main: main.cpp fraction.o
	g++ main.cpp fraction.o -O2 -Wall -Wuninitialized -o main
fraction: fraction.cpp fraction.h
	g++ fraction.cpp -c -O2

