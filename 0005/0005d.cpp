#include <algorithm>
#include <cmath>
#include <iomanip>
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
    std::cout << std::fixed;
    std::cout << std::setprecision(7);

    int a, v, l, d, w_raw;
    std::cin >> a >> v >> l >> d >> w_raw;

    int w = std::min(v, w_raw);

    // before the sign: accelerate from 0 as much as possible until you have to decelerate to hit w exactly

    double sign_speed;
    double before_sign_time;
    
    // for case 1
    double accel_only_speed = std::sqrt(2.0 * a * d);

    // for case 2
    double accel_dist = (v * v) / (2.0 * a);
    double decel_dist = (v * v - w * w) / (2.0 * a);


    // case 1: accelerate all the way to a speed <= w
    if (accel_only_speed <= w)
    {
        sign_speed = accel_only_speed;
        before_sign_time = accel_only_speed / a;
    }
    // case 2: accelerate all the way to v, hold for a bit, then decelerate
    else if (accel_dist + decel_dist <= d)
    {
        sign_speed = w;
        before_sign_time = double(v) / a + double(v - w) / a;
        double remaining_dist = d - accel_dist - decel_dist;
        before_sign_time += remaining_dist / v;

    }
    // case 3: accelerate as much as possible then decelerate without hitting v
    else
    {
        sign_speed = w;
        double peak_v = std::sqrt(w * w / 2.0 + a * d);
        before_sign_time = peak_v / a + (peak_v - w) / a;
    }   

    // after the sign: go from speed min(v, w) to v, limited by what's left of the road (l - d)
    double dist_limited_speed = std::sqrt(sign_speed * sign_speed + 2.0 * a * (l - d));
    
    double after_sign_time;
    // not enough time to ramp up to full speed
    if (dist_limited_speed <= v)
    {
        after_sign_time = (dist_limited_speed - sign_speed) / a;
    }
    else
    {
        after_sign_time = (v - sign_speed) / double(a);
        double accel_dist = (v * v - sign_speed * sign_speed) / (2.0 * a);
        double remaining_dist = (l - d) - accel_dist;
        after_sign_time += remaining_dist / v;
    }

    std::cout << before_sign_time + after_sign_time << std::endl;

    return 0;
}
