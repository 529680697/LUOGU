#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = (1505 << 2);

struct node
{
    int x, y;
    node() {}
    node(int _x, int _y) : x(_x), y(_y) {}
};

int n, m, x, y;
bool g[maxn][maxn], vis[maxn][maxn];
int X[4] = {-1, 0, 1, 0};
int Y[4] = {0, -1, 0, 1};

inline char get_char()
{
    char ch = getchar();
    while (ch != '#' && ch != '.' && ch != 'S')
    {
        ch = getchar();
    }
    return ch;
}

inline bool can_go(int x0, int y0)
{
    if (x0 < 0 || y0 < 0 || x0 >= (n * 3) || y0 >= (m * 3))
        return false;
    if (g[x0][y0])
        return false;
    return true;
}

bool dfs(int x0, int y0)
{
    if (x0 % n == x && y0 % m == y)
        return true;
    for (int i = 0, tx, ty; i < 4; i++)
    {
        tx = x0 + X[i], ty = y0 + Y[i];
        if (can_go(tx, ty) && !vis[tx][ty])
        {
            vis[tx][ty] = true;
            if (dfs(tx, ty))
                return true;
        }
    }
    return false;
}

bool bfs()
{
    vis[x][y] = true;
    queue<node> q;
}

int main()
{
    freopen("in", "r", stdin);
    // ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                char ch = get_char();
                g[i][j] = g[i][j + m] = g[i][j + 2 * m] = (ch == '#' ? 1 : 0);
                g[i + n][j] = g[i + n][j + m] = g[i + n][j + 2 * m] = g[i][j];
                g[i + 2 * n][j] = g[i + 2 * n][j + m] = g[i + 2 * n][j + 2 * m] = g[i][j];
                if (ch == 'S')
                    x = i,
                    y = j;
            }
        memset(vis, 0, sizeof(vis));
        // for (int i = 0; i < 3 * n; i++)
        // {
        //     for (int j = 0; j < 3 * m; j++)
        //     {
        //         cout << g[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << x << y << endl;
        vis[x + n][y + m] = true;
        bool flag = false;
        for (int i = 0, tx, ty; i < 4; i++)
        {
            tx = x + n + X[i], ty = y + m + Y[i];
            if (can_go(tx, ty) && !vis[tx][ty])
            {
                vis[tx][ty] = true;
                if (dfs(tx, ty))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
