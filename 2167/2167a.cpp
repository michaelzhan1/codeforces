#include <cstdio>
#include <cstring>

#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define forinc(i, s, e) for (int i = s; i < e; ++i)
#define fordec(i, e, s) for (int i = e; i >= s; --i)

using ll = long long;

int main()
{
    int n;
    sc(n);

    int a, b, c, d;
    forinc(i, 0, n)
    {
        sc(a), sc(b), sc(c), sc(d);
        if (a == b && a == c && a == d)
        {
            pf("YES\n");
        }
        else
        {
            pf("NO\n");
        }
    }

    return 0;
}
