#include <algorithm>
#include <cstdio>
#include <cstring>

#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define forinc(i, s, e) for (int i = s; i < e; ++i)

using ll = long long;

const int MAXN = 5'000'005;
char s[MAXN], ma[2 * MAXN];
int rad[2 * MAXN], dp[2 * MAXN];
void manacher(char *s, int len0)
{
    int len = 0;
    ma[len++] = '$';
    ma[len++] = '#';
    forinc(i, 0, len0) ma[len++] = s[i], ma[len++] = '#';
    ma[len] = 0;
    int r = 0, center = 0;
    forinc(i, 0, len)
    {
        rad[i] = i < r ? std::min(rad[2 * center - i], r - i) : 1;
        while (ma[i + rad[i]] == ma[i - rad[i]])
            rad[i]++;
        if (i + rad[i] > r)
            r = i + rad[i], center = i;
    }
}
void solve(int len)
{
    ll ans(0);
    forinc(i, 1, len + 1)
    {
        int l = 2, r = 2 * i, m = (l + r) >> 1;
        if (rad[m] * 2 > r - l + 1)
            dp[r] = dp[m - 1 - (m - 1) % 2] + 1;
        ans += dp[r];
    }
    pf("%lld\n", ans);
}
int main()
{
    scs(s);
    int len = (int)std::strlen(s);
    manacher(s, len);
    solve(len);
}