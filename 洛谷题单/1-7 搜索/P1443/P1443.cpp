#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 405;
const int inf = 0x3f3f3f3f;

struct node
{
    int x, y, lev;
    node() {}
    node(int _x, int _y, int _l) : x(_x), y(_y), lev(_l) {}
    node operator+(const node &a) const
    {
        return node(x + a.x, y + a.y, lev + 1);
    }
} a[8];

int n, m, x, y;
int f[maxn][maxn];
bool vis[maxn][maxn];

bool check(node &no)
{
    if (no.x <= 0 || no.x > n || no.y <= 0 || no.y > m)
        return false;
    if (vis[no.x][no.y])
        return false;
    return true;
}

void bfs()
{
    queue<node> q;
    f[x][y] = 0;
    q.push(node(x, y, 0));
    vis[x][y] = true;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            node c = now + a[i];
            if (check(c))
            {
                vis[c.x][c.y] = true;
                f[c.x][c.y] = c.lev;
                q.push(c);
            }
        }
    }
}

void init()
{
    a[0].x = -2, a[0].y = -1;
    a[1].x = -2, a[1].y = 1;
    a[2].x = -1, a[2].y = 2;
    a[3].x = 1, a[3].y = 2;
    a[4].x = 2, a[4].y = 1;
    a[5].x = 2, a[5].y = -1;
    a[6].x = 1, a[6].y = -2;
    a[7].x = -1, a[7].y = -2;
}

int main()
{
    // ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    cin >> n >> m >> x >> y;
    fill(f[0], f[0] + maxn * maxn, inf);
    init();
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (f[i][j] != inf)
                printf("%-5d", f[i][j]);
            else
                printf("%-5d", -1);
        printf("\n");
    }
    return 0;
}