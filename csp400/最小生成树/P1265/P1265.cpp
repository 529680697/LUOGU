#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 5005;
const int inf = 0x3f3f3f3f;

struct node
{
    int x, y;
} no[maxn];

int n;
double d[maxn];
bool vis[maxn];

inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    x = x * f;
}

inline double count_dis(int a, int b)
{
    return sqrt(1.0 * (no[a].x - no[b].x) * (no[a].x - no[b].x) + 1.0 * (no[a].y - no[b].y) * (no[a].y - no[b].y));
}

double prim()
{
    fill(d, d + n, inf);
    d[0] = 0;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        double MIN = inf;
        for (int j = 0; j < n; j++)
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        if (u == -1)
            return -1;
        vis[u] = true;
        ans += d[u];
        for (int j = 0; j < n; j++)
        {
            double dis = count_dis(u, j);
            if (!vis[j] && dis < d[j])
                d[j] = dis;
        }
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    read(n);
    for (int i = 0; i < n; i++)
        read(no[i].x), read(no[i].y);
    double ans = prim();
    printf("%.2lf\n", ans);
    return 0;
}