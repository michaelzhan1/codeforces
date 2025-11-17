#include <algorithm>
#include <cstdio>
#include <cstring>

#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define forinc(i, s, e) for (int i = s; i < e; ++i)
#define fordec(i, e, s) for (int i = e; i >= s; --i)

using ll = long long;

const int MAXN = 8000;
ll arr[MAXN];
ll cost[MAXN];
ll dp[MAXN];

int main()
{
    int t;
    sc(t);

    while (t--)
    {
        int n;
        sc(n);
        forinc(i, 0, n)
            scl(arr[i]);
        
        ll total_cost = 0;
        forinc(i, 0, n)
        {
            scl(cost[i]);
            total_cost += cost[i];
        }
        
        forinc(i, 0, n)
            dp[i] = cost[i];
        
        forinc(i, 0, n)
        {
            forinc(j, 0, i)
            {
                if (arr[i] >= arr[j] && dp[j] + cost[i] > dp[i])
                    dp[i] = dp[j] + cost[i];
            }
        }

        pf("%lld\n", total_cost - *(std::max_element(dp, dp + n)));

    }
    return 0;
}
