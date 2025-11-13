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

ll arr[200000];

int main()
{
    int t;
    sc(t);

    forinc(i, 0, t)
    {
        int n;
        sc(n);

        bool odd = false, even = false;
        forinc(j, 0, n)
        {
            scl(arr[j]);
            if (arr[j] % 2)
            {
                odd = true;
            }
            else
            {
                even = true;
            }

        }
        
        if (odd && even)
        {
            std::sort(arr, arr + n);
        }
        forinc(j, 0, n)
        {
            pf("%lld ", arr[j]);
        }
        pf("\n");
    }
    return 0;
}
