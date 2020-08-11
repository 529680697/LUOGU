#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;

struct node
{
    int x, y;
} no[505];

int s, p;
double d[505];
bool vis[505];

inline double dis(int a, int b)
{
    return sqrt(1.0 * (no[a].x - no[b].x) * (no[a].x - no[b].x) + 1.0 * (no[a].y - no[b].y) * (no[a].y - no[b].y));
}

void prim()
{
    fill(d, d + 505, inf);
    d[0] = 0;
    for (int i = 0; i < p; i++)
    {
        int u = -1;
        double MIN = inf;
        for (int j = 0; j < p; j++)
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        if (u == -1)
            return;
        vis[u] = true;
        for (int j = 0; j < p; j++)
        {
            if (!vis[j])
            {
                double di = dis(u, j);
                if (di < d[j])
                    d[j] = di;
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> s >> p;
    for (int i = 0; i < p; i++)
        cin >> no[i].x >> no[i].y;
    prim();
    sort(d, d + p);
    printf("%.2lf\n", d[p - s]);
    return 0;
}