#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 505;

int n, m;
int f[maxn][maxn], tmp[maxn][maxn];

inline void deal(int x, int y, int r, int z)
{
    int x0 = x - r, y0 = y - r;
    if (z)
    {
        for (int i = 0; i < 2 * r + 1; i++)
            for (int j = 0; j < 2 * r + 1; j++)
                tmp[x0 + i][y0 + j] = f[x0 + j][y0 + 2 * r - i];
        for (int i = 0; i < 2 * r + 1; i++)
            for (int j = 0; j < 2 * r + 1; j++)
                f[x0 + i][y0 + j] = tmp[x0 + i][y0 + j];
    }
    else
    {
        for (int i = 0; i < 2 * r + 1; i++)
            for (int j = 0; j < 2 * r + 1; j++)
                tmp[x0 + i][y0 + j] = f[x0 + 2 * r - j][y0 + i];
        for (int i = 0; i < 2 * r + 1; i++)
            for (int j = 0; j < 2 * r + 1; j++)
                f[x0 + i][y0 + j] = tmp[x0 + i][y0 + j];
    }
}

int main()
{
    int x, y, r, z;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int nn = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = nn++;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> r >> z;
        deal(x, y, r, z);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", f[i][j]);
        printf("\n");
    }
    return 0;
}