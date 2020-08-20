#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct node
{
    double x, y;
} no[20];

int n;
bool vis[20];
double an = (double)0x3f3f3f3f, d[20][20];

inline double dis(int a, int b)
{
    return sqrt((no[a].x - no[b].x) * (no[a].x - no[b].x) + (no[a].y - no[b].y) * (no[a].y - no[b].y));
}

void dfs(int v, double cur, int tot)
{
    if (tot == n)
    {
        an = min(cur, an);
        // return cur;
    }
    // if (cur >= an)
    //     return;
    vis[v] = true;
    double tmp;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            tmp = cur + d[v][i];
            if (tmp >= an)
                continue;
            dfs(i, tmp, tot + 1);
            // tmp_min = min(tmp, tmp_min);
        }
    }
    vis[v] = false;
    // return tmp_min;
}

int main()
{
    freopen("in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> no[i].x >> no[i].y;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            d[i][j] = d[j][i] = dis(i, j);

    // double ans =
    dfs(0, 0, 0);
    printf("%.2lf\n", an);
    return 0;
}