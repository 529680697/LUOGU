#include <iostream>
#include <cstdio>

#define MAXN (int)5e5 + 5

using namespace std;

int n, m;
int a[MAXN];
long long c[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void add(int i, int k)
{
    while (i <= n)
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
    cin >> n >> m;
    int op, x, y, k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        add(i, a[i] - a[i - 1]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            add(x, k);
            add(y + 1, -k);
        }
        else
        {
            scanf("%d", &x);
            cout << sum(x) << endl;
        }
    }
    return 0;
}