#!/bin/sh

# ./run.sh {number} {letter}

padded=$(printf "%04d" "$1")

g++ -Wall -Wpedantic -Wextra -Werror -Wmissing-include-dirs $padded/$padded$2.cpp
./a.out < $padded/$padded$2.txt