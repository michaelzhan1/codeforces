#include <iostream>
#include <string>
#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

int main()
{
    int n;
    std::cin >> n;

    int zi, zj;
    bool has_zero = false;

    vvi f1(n, vi(n));
    vvi f2(n, vi(n));
    vvi dp1(n, vi(n));
    vvi dp2(n, vi(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int x1, x2;
            std::cin >> x1;
            x2 = x1;
            while (x1 % 2 == 0)
            {
                x1 /= 2;
                f1[i][j]++;
            }
            while (x2 % 5 == 0)
            {
                x2 /= 5;
                f2[i][j]++;
            }

            if (x1 == 0)
            {
                f1[i][j] = -1;
                f2[i][j] = -1;
                zi = i;
                zj = j;
                has_zero = true;
            }
        }
    }

    dp1[0][0] = f1[0][0];
    dp2[0][0] = f2[0][0];
    for (int i = 1; i < n; i++) {
        
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
        }
    }

    return 0;
}
