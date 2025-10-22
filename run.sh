#!/bin/sh

# Check for required arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <problem> <extension>"
    exit 1
fi

num=$(expr "$1" : '\([0-9][0-9]*\)[a-z][a-z]*$')
letter=$(expr "$1" : '^[0-9][0-9]*\([a-z][a-z]*\)$')
padded=$(printf "%04d" "$num")

if [ "$2" = "cpp" ]; then
    g++ -Wall -Wpedantic -Wextra -Werror -Wmissing-include-dirs -Wconversion -Wsign-conversion $padded/$padded$letter.cpp
    ./a.out < $padded/$padded$letter.txt
fi

if [ "$2" = "py" ]; then
    python3 $padded/$padded$letter.py < $padded/$padded$letter.txt
fi
