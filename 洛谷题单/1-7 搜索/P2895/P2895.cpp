#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int maxn = 50005;
const int maxm = 305;

struct node
{
    int x, y, t;
    node() {}
    node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
    node operator+(const node &a) const
    {
        return node(x + a.x, y + a.y, t + 1);
    }
    bool operator<(const node &a) const
    {
        return t < a.t;
    }
} no[maxn], a[4];

int n, fall_t;
bool fin[maxm][maxm], now[maxm][maxm], vis[maxm][maxm];

inline bool check(node &x)
{
    if (x.x < 0 || x.y < 0)
        return false;
    if (now[x.x][x.y] || vis[x.x][x.y])
        return false;
    return true;
}

inline void fall(int t)
{
    for (int i = fall_t; i < n && no[i].t <= t; i++)
    {
        if (no[i].t == t)
        {
            fall_t = i;
            now[no[i].x][no[i].y] = true;
            now[no[i].x + 1][no[i].y] = true;
            now[no[i].x][no[i].y + 1] = true;
            if (no[i].x > 0)
                now[no[i].x - 1][no[i].y] = true;
            if (no[i].y > 0)
                now[no[i].x][no[i].y - 1] = true;
        }
    }
}

int bfs()
{
    queue<node> q;
    q.push(node(0, 0, 0));
    fall(0);
    vis[0][0] = true;
    while (!q.empty())
    {
        node now1 = q.front();
        q.pop();
        fall(now1.t + 1);
        for (int i = 0; i < 4; i++)
        {
            node c = now1 + a[i];
            // cout << c.t << endl;
            if (check(c))
            {
                if (!fin[c.x][c.y])
                    return c.t;
                q.push(c);
                vis[c.x][c.y] = true;
            }
        }
    }
    return -1;
}

void init()
{
    a[0].x = -1, a[0].y = 0;
    a[1].x = 1, a[1].y = 0;
    a[2].x = 0, a[2].y = -1;
    a[3].x = 0, a[3].y = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> no[i].x >> no[i].y >> no[i].t;
    for (int i = 0; i < n; i++)
    {
        fin[no[i].x][no[i].y] = true;
        fin[no[i].x + 1][no[i].y] = true;
        fin[no[i].x][no[i].y + 1] = true;
        if (no[i].x > 0)
            fin[no[i].x - 1][no[i].y] = true;
        if (no[i].y > 0)
            fin[no[i].x][no[i].y - 1] = true;
    }
    if (!fin[0][0])
    {
        cout << 0 << endl;
        return 0;
    }
    init();
    sort(no, no + n);
    int ans = bfs();
    cout << ans << endl;
    return 0;
}