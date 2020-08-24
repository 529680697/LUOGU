#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct node
{
    int x, y;
    bool operator<(const node &a) const
    {
        if (x > a.x)
            return true;
        else if (x == a.x)
            return y > a.y;
        else
            return false;
    }
} no[12];

int n, m, xline[15];
char f[5000][10000];
vector<int> s[2];

inline void init_x_line(int line)
{
    int i = line - 1;
    for (int j = 1; i >= 0; i--)
    {
        if (f[i][i] == 'o')
            xline[j++] = i;
    }
}

void delete_o_node(int line, int x, int y)
{
    if (x < 0)
        return;
    if (f[x][y] == 'o')
    {
        delete_o_node(line, x - 1, y - 1);
        delete_o_node(line, x - 1, y + 1);
    }
    else if (f[x][y] == '\\')
        delete_o_node(line, x - 1, y + 1);
    else if (f[x][y] == '/')
        delete_o_node(line, x - 1, y - 1);
    f[x][y] = ' ';
}

inline void delete_node(int line, int x, int y)
{
    int _x = xline[x], _y = 0;
    for (int j = 0; _y < 2 * line && j < y; _y++)
        if (f[_x][_y] == 'o')
            j++;
    --_y;
    if (y % 2 == 1)
        for (int i = _x + 1, j = _y + 1; i < line && f[i][j] != 'o'; i++, j++)
            f[i][j] = ' ';
    else
        for (int i = _x + 1, j = _y - 1; i < line && f[i][j] != 'o'; i++, j--)
            f[i][j] = ' ';
    delete_o_node(line, _x, _y);
    f[_x][_y] = ' ';
}

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int len = 3 * (1 << (n - 1)) - 1;
    for (int i = 0; i < 5000; i++)
    {
        fill(f[i], f[i] + len, ' ');
        f[i][len] = '\0';
    }
    for (int i = 0, j = 0; i < (1 << (n - 2)); i++, j += 6)
    {
        s[0].push_back(j), s[0].push_back(j + 4);
        f[0][j] = f[0][j + 4] = 'o';
    }
    int cur = 0, next = cur ^ 1, line = 1;
    while (!s[cur].empty())
    {
        if (s[cur].size() == 1)
        {
            f[line][s[cur][0]] = 'o';
            break;
        }
        s[next].clear();
        for (int i = 0; i < s[cur].size(); i += 2)
        {
            int l = s[cur][i] + 1, r = s[cur][i + 1] - 1;
            if (l == r)
            {
                f[line][l] = 'o';
                s[next].push_back(l);
            }
            else
            {
                f[line][l] = '/', f[line][r] = '\\';
                s[next].push_back(l), s[next].push_back(r);
            }
        }
        line++, cur = next, next ^= 1;
    }
    init_x_line(line);
    for (int i = 0; i < m; i++)
        cin >> no[i].x >> no[i].y;
    sort(no, no + m);
    for (int i = 0; i < m; i++)
        delete_node(line, no[i].x, no[i].y);
    for (int i = line - 1; i >= 0; i--)
        cout << f[i] << endl;
    return 0;
}