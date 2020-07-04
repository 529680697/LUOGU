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
    int op, x, y;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        add(i, a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
        {
            add(x, y);
        }
        else
        {
            cout << sum(y) - sum(x - 1) << endl;
        }
    }
    return 0;
}