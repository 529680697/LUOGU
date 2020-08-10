#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10000005;

int n, m, vis[maxn], color[maxn];

inline int read_num()
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
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    int l, r, w, ans = 0;
    freopen("in.txt", "r", stdin);
    n = read_num(), m = read_num();
    for (int i = 1; i <= m; i++)
    {
        l = read_num(), r = read_num();
        for (int j = l; j <= r; j++)
            color[j] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            w = 1;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[color[i]])
        {
            ans++;
            vis[color[i]] = true;
        }
    }
    cout << ans - w << endl;
    return 0;
}