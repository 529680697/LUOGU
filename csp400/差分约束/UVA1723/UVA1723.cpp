#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e4 + 5;

struct node
{
    int a, b, c;
    bool operator<(const node &x) const
    {
        if (b == x.b)
            return x.a < a;
        else
            return b < x.b;
    }
} no[maxn];

int t, n, a[maxn], c[maxn];

int lowbit(int x)
{
    return x & -x;
}

void add(int i, int k)
{
    while (i < maxn)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

long long sum(int i)
{
    long long r = 0;
    while (i > 0)
    {
        r += c[i];
        i -= lowbit(i);
    }
    return r;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> no[i].a >> no[i].b >> no[i].c;
        sort(no, no + n);
        fill(a, a + maxn, 0);
        fill(c, c + maxn, 0);
        // for (int i = 0; i < n; i++)
        //     cout << no[i].a << no[i].b << no[i].c << endl;
        for (int i = 0; i < n; i++)
        {
            int need = no[i].c;
            need -= sum(no[i].b);
            need += sum(no[i].a - 1);
            if (need > 0)
            {
                for (int l = no[i].b, num = 0; num < need && l >= no[i].a; l--)
                {
                    if (!a[l])
                    {
                        a[l] = 1;
                        add(l, 1);
                        num++;
                    }
                }
            }
        }
        cout << sum(no[n - 1].b) << endl;
        if (t)
            cout << endl;
    }
    return 0;
}