#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 10005;

int t, n, a[maxn], b[maxn], c[maxn];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}

inline double f(double x, int i)
{
    return a[i] * x * x + b[i] * x + c[i];
}

double F(double x)
{
    double ans = f(x, 0);
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, f(x, i));
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    t = read();
    while (t--)
    {
        n = read();
        for (int i = 0; i < n; i++)
            a[i] = read(), b[i] = read(), c[i] = read();
        double l = 0, r = 1000, emp = 1e-11, mid1, mid2;
        while (r - l > emp)
        {
            mid1 = l + (r - l) / 3.0;
            mid2 = r - (r - l) / 3.0;
            if (F(mid1) > F(mid2))
                l = mid1;
            else
                r = mid2;
        }
        printf("%.4lf\n", F(l));
    }
    return 0;
}