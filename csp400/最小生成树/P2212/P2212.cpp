#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 2005;
const int inf = 0x3f3f3f3f;

struct node
{
    int x, y;
} no[maxn];

int n, c;
int d[maxn];
bool vis[maxn];

inline int dis(int a, int b)
{
    return (no[a].x - no[b].x) * (no[a].x - no[b].x) + (no[a].y - no[b].y) * (no[a].y - no[b].y);
}

long long prim()
{
    fill(d, d + maxn, inf);
    d[0] = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1, MIN = inf;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        }
        if (u == -1)
            return -1;
        ans += d[u];
        vis[u] = true;
        for (int j = 0; j < n; j++)
        {
            int di = dis(u, j);
            if (!vis[j] && di >= c && di < d[j])
                d[j] = di;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> no[i].x >> no[i].y;
    cout << prim() << endl;
    return 0;
}