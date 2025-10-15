#!/bin/sh

# ./run.sh {number} {letter}

padded=$(printf "%04d" "$1")

if [ -f "$padded/$padded$2.cpp" ]; then
    g++ -Wall -Wpedantic -Wextra -Werror -Wmissing-include-dirs $padded/$padded$2.cpp
    ./a.out < $padded/$padded$2.txt
fi

if [ -f "$padded/$padded$2.py" ]; then
    python3 $padded/$padded$2.py < $padded/$padded$2.txt
fi
