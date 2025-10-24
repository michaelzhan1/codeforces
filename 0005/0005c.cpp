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
    std::string line;
    std::cin >> line;

    std::vector<size_t> open_stack; // track indices of last seen open parentheses
    std::vector<size_t> seq_lens(line.size() + 1); // length of sequence, should never overlap

    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] == '(')
        {
            open_stack.push_back(i);
        }
        // something to pop
        else if (open_stack.size() > 0)
        {
            size_t open_i = open_stack.back();
            open_stack.pop_back();

            seq_lens[open_i] = i - open_i + 1;
        }
    }

    std::vector<size_t> comb_lens(line.size() + 1);
    size_t i = 0;
    while (i < seq_lens.size())
    {
        if (seq_lens[i] > 0)
        {
            comb_lens[i + seq_lens[i]] += comb_lens[i] + seq_lens[i];
            i += seq_lens[i];
        }
        else
        {
            i++;
        }
    }

    auto max_it = std::max_element(comb_lens.begin(), comb_lens.end());
    size_t max_val = *max_it;
    
    if (max_val == 0)
    {
        std::cout << '0' << ' ' << '1' << std::endl;
    }
    else
    {
        std::cout << max_val << ' ' << std::count(comb_lens.begin(), comb_lens.end(), max_val) << std::endl;;
    }
    return 0;
}
