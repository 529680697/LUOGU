#include <iostream>
#include <cstdio>

#define lowbit(i) ((i) & (-i))
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

int n, m;
ll a[maxn];

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

void update(int x, ll k)
{
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += k;
}

ll sum(int x)
{
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += a[i];
    return ans;
}

int main()
{
    int a, b;
    char op;
    freopen("in.txt", "r", stdin);
    n = read(), m = read();
    while (m--)
    {
        scanf("%c", &op);
        if (op == 'x')
        {
            a = read(), b = read();
            update(a, b);
        }
        else
        {
            a = read(), b = read();
            printf("%lld\n", sum(b) - sum(a - 1));
        }
    }

    return 0;
}