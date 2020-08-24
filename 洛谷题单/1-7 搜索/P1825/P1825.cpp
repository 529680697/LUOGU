#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
const int maxn = 305;

struct node
{
    int x, y, dep;
    node() {}
    node(int _x, int _y, int _d) : x(_x), y(_y), dep(_d) {}
    node operator+(const node &a) const
    {
        return node(x + a.x, y + a.y, dep + 1);
    }
} next_pos[4];

int n, m, x, y, end_x, end_y;
char g[maxn][maxn];
bool vis[maxn][maxn];
vector<node> go[30];

inline bool can_go(node &a)
{
    if (a.x < 0 || a.y < 0 || a.x >= n || a.y >= m)
        return false;
    if (vis[a.x][a.y])
        return false;
    vis[a.x][a.y] = true;
    if (g[a.x][a.y] == '#')
        return false;
    else if (isalpha(g[a.x][a.y]))
    {
        int no = g[a.x][a.y] - 'A';
        if (go[no][0].x == a.x && go[no][0].y == a.y)
            a.x = go[no][1].x, a.y = go[no][1].y;
        else
            a.x = go[no][0].x, a.y = go[no][0].y;
    }
    return true;
}

int bfs()
{
    queue<node> q;
    q.push(node(x, y, 0));
    vis[x][y] = true;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();

        if (now.x == end_x && now.y == end_y)
            return now.dep;
        for (int i = 0; i < 4; i++)
        {
            node tmp = now + next_pos[i];
            if (can_go(tmp))
                q.push(tmp);
        }
    }
    return -1;
}

void init()
{
    next_pos[0].x = -1, next_pos[0].y = 0;
    next_pos[1].x = 1, next_pos[1].y = 0;
    next_pos[2].x = 0, next_pos[2].y = -1;
    next_pos[3].x = 0, next_pos[3].y = 1;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == '@')
                x = i, y = j;
            else if (g[i][j] == '=')
                end_x = i, end_y = j;
            else if (isalpha(g[i][j]))
                go[g[i][j] - 'A'].push_back(node(i, j, 0));
        }
    }
    init();
    cout << bfs() << endl;
    return 0;
}