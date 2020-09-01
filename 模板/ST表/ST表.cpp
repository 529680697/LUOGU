//求解静态区间最大值
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, st[maxn][32], lg[maxn];

inline int query(int l, int r)
{
    int len = log2(r - l + 1);
    return max(st[l][len], st[r - (1 << len) + 1][len]);
}

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
        x = (x << 1) + (x << 3) + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int main()
{
    //    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    // cin >> n >> m;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = read();
        // cout << -1 << endl;
        // lg[i] = lg[i / 2] + 1;
    }

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    int l, r;
    for (int i = 0; i < m; i++)
    {
        l = read(), r = read();
        //        cout << query(l, r) << endl;
        printf("%d\n", query(l, r));
    }
    return 0;
}