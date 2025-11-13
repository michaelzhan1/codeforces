#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <numeric>

#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define forinc(i, s, e) for (int i = s; i < e; ++i)
#define fordec(i, e, s) for (int i = e; i >= s; --i)

using ll = long long;

ll arr[100000];

int main()
{
    int t;
    sc(t);

    forinc(i, 0, t)
    {
        int n;
        sc(n);

        bool found = false;
        ll minval = LLONG_MAX;

        forinc(j, 0, n)
        {
            scl(arr[j]);
            if (arr[j] % 2 == 1 && !found)
            {
                pf("2\n");
                found = true;
            }

            minval = std::min(minval, arr[j]);
        }

        if (found) continue;

        for (ll j = 3; j <= std::max(minval, 3LL); j += 2)
        {
            for (size_t k = 0; k < size_t(n); k++)
            {
                if (std::gcd(arr[k], j) == 1)
                {
                    pf("%lld\n", j);
                    found = true;
                    break;
                }
            }

            if (found)
                break;
        }

        if (!found)
            pf("-1\n");
    }
    return 0;
}
