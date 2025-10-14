#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iomanip>

const double PI = std::atan(1.0) * 4;

struct Point
{
    double x;
    double y;
};

double distance(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

double cosLaw(double a, double b, double c)
{
    double tmp = (a * a + b * b - c * c) / (2 * a * b);
    return std::acos(tmp);
}

int guessDenom(double frac)
{
    for (int i = 1; i <= 100; ++i)
    {
        double tmp = frac * i;
        if (std::abs(std::round(tmp) - tmp) < 0.0001)
        {
            return i;
        }
    }
    return -1;
}

int guessN(double t1, double t2, double t3)
{
    double d = std::min(std::min(t1, t2), t3);

    double tmp1 = t1 / d;
    double tmp2 = t2 / d;
    double tmp3 = t3 / d;

    int d1 = guessDenom(tmp1);
    int d2 = guessDenom(tmp2);
    int d3 = guessDenom(tmp3);

    int denom = std::lcm(std::lcm(d1, d2), d3);
    return std::round(tmp1 * denom) + std::round(tmp2 * denom) + std::round(tmp3 * denom);
}

int main()
{
    Point p1, p2, p3;
    std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    // sides opposite points
    double a = distance(p2, p3);
    double b = distance(p1, p3);
    double c = distance(p1, p2);

    // central angles corresponding with points (rad)
    double t1 = cosLaw(b, c, a) * 2;
    double t2 = cosLaw(c, a, b) * 2;
    double t3 = cosLaw(a, b, c) * 2;

    // find n by lcm of denominators
    int n = guessN(t1, t2, t3);

    // circumradius
    double r = a / (2 * std::sin(t1 / 2));

    // final area
    double res = n * r * r / 2 * std::sin(2 * PI / n);

    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << res << std::endl;

    return 0;
}
