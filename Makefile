CC=g++
OPTION=-std=c++11 -fopenmp -O2
SORCE=main.cpp input.hpp output.hpp particle.hpp util.hpp \
main_functions.hpp point.hpp world.hpp edge.hpp
TARGET=main.cpp

output: ${SORCE}
	${CC} ${OPTION} ${TARGET}
