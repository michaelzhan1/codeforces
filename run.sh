#!/bin/sh

# Check for required arguments
if [ $# -lt 3 ]; then
    echo "Usage: $0 <number> <suffix> <extension>"
    exit 1
fi

padded=$(printf "%04d" "$1")

if [ "$3" = "cpp" ]; then
    g++ -Wall -Wpedantic -Wextra -Werror -Wmissing-include-dirs $padded/$padded$2.cpp
    ./a.out < $padded/$padded$2.txt
fi

if [ "$3" = "py" ]; then
    python3 $padded/$padded$2.py < $padded/$padded$2.txt
fi
