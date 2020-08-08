#include <iostream>
#include <cstdio>

#define lowbit(i) ((i) & (-i))
using namespace std;
const int maxn = 1e7 + 5;

int n, m, a[maxn];

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

void update(int x, int k)
{
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += k;
}

int sum(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        ans += a[i];
    }
    return ans;
}

int main()
{
    int op, a, b;
    freopen("in.txt", "r", stdin);
    n = read(), m = read();
    while (m--)
    {
        op = read();
        if (op)
        {
            a = read();
            printf("%d\n", sum(a));
        }
        else
        {
            a = read(), b = read();
            update(a, 1), update(b + 1, -1);
        }
    }

    return 0;
}