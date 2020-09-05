#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;

struct nofr
{
    int x, y;
} no[maxn];

int n, k;
double dis[maxn][maxn], d[maxn];
bool vis[maxn];

inline double get_dis(int x, int y)
{
    if (dis[x][y] != 0)
        return dis[x][y];
    return dis[x][y] = dis[y][x] = sqrt((no[x].x - no[y].x) * (no[x].x - no[y].x) + (no[x].y - no[y].y) * (no[x].y - no[y].y));
}

void prim()
{
    fill(d, d + n, inf);
    d[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        double MIN = inf;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        }
        vis[u] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && get_dis(u, j) < d[j])
                d[j] = get_dis(u, j);
        }
    }
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> no[i].x >> no[i].y;
    prim();
    nth_element(d, d + n - k + 1, d + n);
    cout << fixed << setprecision(2) << d[n - k + 1] << endl;
    return 0;
}