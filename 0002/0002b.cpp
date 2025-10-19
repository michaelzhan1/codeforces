#include <iostream>
#include <string>
#include <vector>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

int main()
{
    int n;
    std::cin >> n;

    int zi, zj = -1;
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
            while (x1 > 0 && x1 % 2 == 0)
            {
                x1 /= 2;
                f1[i][j]++;
            }
            while (x2 > 0 && x2 % 5 == 0)
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

    dp1[n - 1][n - 1] = f1[n - 1][n - 1];
    dp2[n - 1][n - 1] = f2[n - 1][n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        dp1[i][n - 1] = dp1[i + 1][n - 1] == -1 ? -1 : f1[i][n - 1] + dp1[i + 1][n - 1];
        dp2[i][n - 1] = dp2[i + 1][n - 1] == -1 ? -1 : f2[i][n - 1] + dp2[i + 1][n - 1];

        dp1[n - 1][i] = dp1[n - 1][i + 1] == -1 ? -1 : f1[n - 1][i] + dp1[n - 1][i + 1];
        dp2[n - 1][i] = dp2[n - 1][i + 1] == -1 ? -1 : f2[n - 1][i] + dp2[n - 1][i + 1];
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = n - 2; j >= 0; --j)
        {
            if (f1[i][j] == -1)
                dp1[i][j] = -1;
            else if (dp1[i + 1][j] == -1 && dp1[i][j + 1] == -1)
                dp1[i][j] = -1;
            else if (dp1[i + 1][j] == -1)
                dp1[i][j] = f1[i][j] + dp1[i][j + 1];
            else if (dp1[i][j + 1] == -1)
                dp1[i][j] = f1[i][j] + dp1[i + 1][j];
            else
                dp1[i][j] = f1[i][j] + std::min(dp1[i + 1][j], dp1[i][j + 1]);

            if (f2[i][j] == -1)
                dp2[i][j] = -1;
            else if (dp2[i + 1][j] == -1 && dp2[i][j + 1] == -1)
                dp2[i][j] = -1;
            else if (dp2[i + 1][j] == -1)
                dp2[i][j] = f2[i][j] + dp2[i][j + 1];
            else if (dp2[i][j + 1] == -1)
                dp2[i][j] = f2[i][j] + dp2[i + 1][j];
            else
                dp2[i][j] = f2[i][j] + std::min(dp2[i + 1][j], dp2[i][j + 1]);
        }
    }

    // if there's a zero and it's worth taking, path to (zi, zj) directly
    if (has_zero && std::min(dp1[0][0], dp2[0][0]) >= 1) {
        std::cout << 1 << std::endl;
        for (int i = 0; i < zi; ++i)
            std::cout << 'D';
        for (int j = 0; j < zj; ++j)
            std::cout << 'R';
        for (int i = zi; i < n - 1; ++i)
            std::cout << 'D';
        for (int j = zj; j < n - 1; ++j)
            std::cout << 'R';
        std::cout << std::endl;
        return 0;
    }

    // else, it's better to not take the zero (or there is no zero)
    vvi dp = dp1[0][0] < dp2[0][0] ? dp1 : dp2;
    std::cout << dp[0][0] << std::endl;
    int i = 0, j = 0;
    while (i < n - 1 && j < n - 1) {
        if (dp[i + 1][j] == -1) {
            std::cout << 'R';
            j++;
        } else if (dp[i][j + 1] == -1) {
            std::cout << 'D';
            i++;
        } else if (dp[i + 1][j] < dp[i][j + 1]) {
            std::cout << 'D';
            i++;
        } else {
            std::cout << 'R';
            j++;
        }
    }

    while (i < n - 1) {
        std::cout << 'D';
        i++;
    }

    while (j < n - 1) {
        std::cout << 'R';
        j++;
    }

    std::cout << std::endl;

    return 0;
}
