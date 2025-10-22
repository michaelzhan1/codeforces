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
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// nums
using ll = long long;

// vectors
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using vs = std::vector<size_t>;

// sets
using usi = std::unordered_set<int>;
using uss = std::unordered_set<size_t>;

// pairs
template <typename T1, typename T2>
inline std::pair<T1, T2> mp(T1 a, T2 b)
{
    return std::make_pair(a, b);
}

// pair hashing
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

// problem specific

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
