 #!/bin/sh
 
 flags=-std=c++11
 
 
 g++ $flags -o build/test_utils.o -c test/test_utils.cpp
 g++ $flags -o build/link_list_node.o -c src/link_list_node.cpp
 g++ $flags -o build/main.o -c test/main.cpp
 g++ $flags -o bin/output_program build/main.o build/test_utils.o build/link_list_node.o
 