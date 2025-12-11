#include <cstdio>
#include <cstring>

#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define forinc(i, s, e) for (int i = s; i < e; ++i)
#define fordec(i, e, s) for (int i = e; i >= s; --i)

using ll = long long;

const int MAXN = 100;

int main()
{
    int t;
    sc(t);
    forinc(ti, 0, t)
    {
        int n;
        sc(n);

        int arr[MAXN];
        forinc(i, 0, n)
        {
            sc(arr[i]);
        }

        int res = 0;
        fordec(j, n - 1, 1)
        {
            fordec(i, j - 1, 0)
            {
                if (arr[i] > arr[j])
                {
                    res++;
                    break;
                }
            }
        }

        pf("%d\n", res);
    }

    return 0;
}
