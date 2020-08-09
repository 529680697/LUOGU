#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1005;
const int inf = 0x3f3f3f3f;

struct node
{
    int x, y;
} no[maxn];

int n, m;
bool connected[maxn][maxn], vis[maxn];
double d[maxn];

inline double dis(int a, int b)
{
    double xx = 1.0 * (no[a].x - no[b].x) * (no[a].x - no[b].x);
    double yy = 1.0 * (no[a].y - no[b].y) * (no[a].y - no[b].y);
    return sqrt(xx + yy);
}

inline void frush_d(int x)
{
    for (int i = 1; i <= n; i++)
        if (i != x && !vis[i])
        {
            if (connected[x][i])
            {
                d[i] = min(d[i], dis(i, x));
                vis[i] = true;
                frush_d(i);
            }
            else
            {
                d[i] = min(d[i], dis(i, x));
            }
        }
}

double prim()
{
    fill(d, d + maxn, inf);
    d[1] = 0;
    double ans = 0;
    frush_d(1);
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        double MIN = inf;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        if (u == -1)
            return ans;
        vis[u] = true;
        ans += d[u];
        frush_d(u);
    }
    return ans;
}

int main()
{
    int a, b;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> no[i].x >> no[i].y;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        connected[b][a] = connected[a][b] = true;
    }
    double ans = prim();
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}