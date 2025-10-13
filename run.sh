#!/bin/sh

# ./run.sh {number} {letter}

g++ -Wall -Wpedantic -Wextra -Werror -Wmissing-include-dirs $1/$1$2.cpp
./a.out < $1/$1$2.txt