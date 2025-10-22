#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <numeric>

// nums
using ll = long long;

// vectors
using vi = std::vector<int>;
using vvi = std::vector<vi>;

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
    size_t d;
    int sum_time;
    std::cin >> d >> sum_time;

    vi min_time(d), max_time(d);
    int min, max;
    for (size_t i = 0; i < d; ++i)
    {
        std::cin >> min >> max;
        min_time[i] = min;
        max_time[i] = max;
    }

    int min_sum = std::accumulate(min_time.begin(), min_time.end(), 0);
    int max_sum = std::accumulate(max_time.begin(), max_time.end(), 0);
    if (sum_time < min_sum || sum_time > max_sum)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }

    vi times(min_time);
    int cur_sum = min_sum;

    size_t i = 0;
    int to_add;
    while (i < d && cur_sum < sum_time)
    {
        to_add = std::min(sum_time - cur_sum, max_time[i] - min_time[i]);
        times[i] += to_add;
        cur_sum += to_add;

        if (times[i] == max_time[i])
            i++;
    }

    std::cout << "YES" << std::endl;
    for (size_t i = 0; i < d; i++)
    {
        if (i > 0)
            std::cout << ' ';
        std::cout << times[i];
    }
    std::cout << std::endl;

    return 0;
}
