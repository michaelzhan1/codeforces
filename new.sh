#!/bin/sh

# Check for required arguments
if [ $# -lt 2 ]; then
    echo "Usage: $0 <problem> <extension>"
    exit 1
fi

num=$(expr "$1" : '\([0-9][0-9]*\)[a-z][a-z]*$')
letter=$(expr "$1" : '^[0-9][0-9]*\([a-z][a-z]*\)$')
ext="$2"

# Pad number to 4 digits
padded=$(printf "%04d" "$num")

# File paths
dir="$padded"
base="$dir/$padded$letter"
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
#include <cstdio>
#include <cstring>

#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define forinc(i, s, e) for (int i = s; i < e; ++i)
#define fordec(i, e, s) for (int i = e; i >= s; --i)

using ll = long long;

int main()
{
    return 0;
}
EOF
        ;;
    py)
        cat > "$src" << EOF
def read(to_type):
    return to_type(input())

def read_arr(to_type):
    return list(map(to_type, input().strip().split()))

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
