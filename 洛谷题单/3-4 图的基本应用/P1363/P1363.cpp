#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 1505;

int n, m, x, y, s[maxn][maxn][2];
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

inline bool can_go(int &x0, int &y0, int &step_x, int &step_y)
{
    if (x0 < 0)
        x0 = n - 1, step_x--;
    else if (x0 >= n)
        x0 = 0, step_x++;
    else if (y0 < 0)
        y0 = m - 1, step_y--;
    else if (y0 >= m)
        y0 = 0, step_y++;
    if (g[x0][y0])
        return false;
    return true;
}

bool dfs(int x0, int y0, int step_x, int step_y)
{
    if (vis[x0][y0])
    {
        if (s[x0][y0][0] != step_x || s[x0][y0][1] != step_y)
            return true;
        return false;
    }
    vis[x0][y0] = true;
    s[x0][y0][0] = step_x;
    s[x0][y0][1] = step_y;
    for (int i = 0, tx, ty; i < 4; i++)
    {
        tx = x0 + X[i], ty = y0 + Y[i];
        int tsx = step_x, tsy = step_y;
        if (can_go(tx, ty, tsx, tsy))
        {
            if (dfs(tx, ty, tsx, tsy))
                return true;
        }
    }
    return false;
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
                g[i][j] = (ch == '#' ? 1 : 0);
                if (ch == 'S')
                    x = i,
                    y = j;
            }
        memset(vis, 0, sizeof(vis));
        memset(s, 0, sizeof(s));
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << g[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << x << y << endl;
        if (dfs(x, y, 0, 0))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
