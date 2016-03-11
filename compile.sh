 #!/bin/sh
 
 flags=-std=c++11
 
 
 g++ $flags -o build/rand_lfsr.o -c test/rand_lfsr.cpp
 g++ $flags -o build/rand_32bit_gen.o -c test/rand_32bit_gen.cpp
 g++ $flags -o build/main.o -c test/main.cpp
 g++ $flags -o build/mergesort.o -c src/mergesort.cpp
 g++ $flags -o bin/output_program build/main.o build/rand_lfsr.o build/rand_32bit_gen.o build/mergesort.o
 