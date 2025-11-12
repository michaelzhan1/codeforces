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

char s[21];
char t[21];

int main()
{
    int q;
    sc(q);

    int n;

    forinc(i, 0, q)
    {
        sc(n);
        scs(s), scs(t);

        std::sort(s, s + n);
        std::sort(t, t + n);
        if (std::strncmp(s, t, (size_t)n))
        {
            pf("NO\n");
        }
        else{
            pf("YES\n");
        }
    }

    return 0;
}
