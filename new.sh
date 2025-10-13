#!/bin/sh

# Extract number and letter
num=$(echo "$1" | grep -o '^[0-9]\+')
let=$(echo "$1" | grep -o '[a-zA-Z]$')

# Pad number to 4 digits
padded=$(printf "%04d%s" "$num" "$let")

mkdir "$num"
touch "$num/$padded.cpp"
touch "$num/$padded.txt"

cat << EOF >> "$padded.cpp"
#include <iostream>
#include <string>

int main()
{
    return 0;
}
EOF