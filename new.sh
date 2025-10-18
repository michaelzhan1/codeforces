#!/bin/sh

# Check for required arguments
if [ $# -lt 3 ]; then
    echo "Usage: $0 <number> <suffix> <extension>"
    exit 1
fi

num="$1"
suffix="$2"
ext="$3"

# Pad number to 4 digits
padded=$(printf "%04d" "$num")

# File paths
dir="$padded"
base="$dir/$padded$suffix"
src="$base.$ext"
txt="$base.txt"

# Exit if file already exists
if [ -f "$src" ]; then
    exit 0
fi

# Create directory and files
mkdir -p "$dir"
touch "$txt"

case "$ext" in
    cpp)
        cat > "$src" << EOF
#include <iostream>
#include <string>
#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

int main()
{
    return 0;
}
EOF
        ;;
    py)
        cat > "$src" << EOF
def main():
    pass

if __name__ == "__main__":
    main()
EOF
        ;;
    *)
        touch "$src"
        ;;
esac
