#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 1e6 + 1e5;

int n, m, v, x;
int aa[maxn << 1], bb[maxn << 1];

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

int main()
{
    freopen("in.txt", "r", stdin);
    n = read(), m = read();
    int *a = aa + maxn, *b = bb + maxn;
    for (int i = 0; i < n; i++)
    {
        v = read(), x = read();
        a[x - (v << 1) - v + 1]++;
        a[x - (v << 1) + 1] -= 2;
        a[x + 1] += 2;
        a[x + (v << 1) + 1] -= 2;
        a[x + (v << 1) + v + 1]++;
    }
    // for (int i = 0; i <= m; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    for (int i = -40000; i < m + 40000; i++)
    {
        a[i] += a[i - 1];
        b[i] = b[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}