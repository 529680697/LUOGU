#include <iostream>
#include <cstdio>

#define MAXN 100005
#define ll long long

using namespace std;

int n, m;
ll a[MAXN];
ll s[MAXN], ss[MAXN];

ll lowbit(ll x)
{
    return x & -x;
}

void add1(ll i, ll k)
{
    while (i <= n)
    {
        s[i] += k;
        i += lowbit(i);
    }
}

ll sum1(ll i)
{
    ll r = 0;
    while (i > 0)
    {
        r += s[i];
        i -= lowbit(i);
    }
    return r;
}

void add2(ll i, ll k)
{
    while (i <= n)
    {
        ss[i] += k;
        i += lowbit(i);
    }
}

ll sum2(ll i)
{
    ll r = 0;
    while (i > 0)
    {
        r += ss[i];
        i -= lowbit(i);
    }
    return r;
}

int main()
{
    char op[128];
    ll num, x;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        add1(i, a[i]);
        add2(i, i * a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            scanf("%lld", &num);
            printf("%lld\n", (num + 1) * sum1(num) - sum2(num));
        }
        else
        {
            scanf("%lld%lld", &num, &x);
            add1(num, x - a[num]);
            add2(num, (x - a[num]) * num);
            a[num] = x;
        }
    }

    return 0;
}
