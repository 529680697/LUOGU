#include <iostream>
#include <cstdio>
#include <algorithm>
#define lowbit(i) ((i) & (-i))
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

int n, m, a[maxn], c[maxn], s[maxn], bit1[maxn], num[maxn], cnt = 0;
char op[maxn];
ll bit2[maxn];

inline int read_int()
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
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline char read_char()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

void add1(int x, int v)
{
    for (int i = x; i <= cnt; i += lowbit(i))
    {
        bit1[i] += v;
    }
}

void add2(int x, ll v)
{
    for (int i = x; i <= cnt; i += lowbit(i))
    {
        bit2[i] += v;
    }
}

int sum1(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        ans += bit1[i];
    }
    return ans;
}

ll sum2(int x)
{
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        ans += bit2[i];
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    n = read_int(), m = read_int();
    for (int i = 1; i <= m; i++)
    {
        op[i] = read_char(), c[i] = read_int(), s[i] = read_int();
        num[++cnt] = s[i];
    }
    sort(num + 1, num + m + 1);
    cnt = unique(num + 1, num + m + 1) - num - 1;
    for (int x, i = 1; i <= m; i++)
    {
        s[i] = lower_bound(num + 1, num + cnt + 1, s[i]) - num;
        if (op[i] == 'U')
        {
            if ((x = a[c[i]]))
            {
                add1(x, -1);
                add2(x, -num[x]);
            }
            x = a[c[i]] = s[i];
            add1(x, 1);
            add2(x, num[x]);
        }
        else
        {
            x = sum1(cnt) - sum1(s[i] - 1);
            ll sum = sum2(s[i] - 1);
            if (sum >= (c[i] - x) * 1ll * num[s[i]])
                printf("TAK\n");
            else
                printf("NIE\n");
        }
    }

    return 0;
}