#!/bin/sh

# Pad number to 4 digits
padded=$(printf "%04d" "$1")

if [ -f "$padded/$padded$2.cpp" ]; then
    exit 0
fi

mkdir -p "$padded"
touch "$padded/$padded$2.cpp"
touch "$padded/$padded$2.txt"

cat << EOF >> "$padded/$padded$2.cpp"
#include <iostream>
#include <string>

int main()
{
    return 0;
}
EOF