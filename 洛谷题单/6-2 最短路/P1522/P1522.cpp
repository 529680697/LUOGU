#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 155;

struct node
{
    int x, y;
} no[maxn];

int n;
bool g[maxn][maxn];
double dis[maxn][maxn], max1[maxn], l1, l2 = inf;

inline double cal(int i, int j)
{
    return sqrt((no[i].x - no[j].x) * (no[i].x - no[j].x) + (no[i].y - no[j].y) * (no[i].y - no[j].y));
}

int main()
{
    char c;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> no[i].x >> no[i].y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            g[i][j] = c - '0';
            if (g[i][j])
                dis[i][j] = cal(i, j);
            else if (i != j)
                dis[i][j] = inf;
        }
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         cout << g[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << fixed << setprecision(6) << dis[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (dis[i][j] != inf)
                max1[i] = max(max1[i], dis[i][j]);
        l1 = max(l1, max1[i]);
        // cout << max1[i] << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dis[i][j] == inf)
                l2 = min(max1[i] + max1[j] + cal(i, j), l2);
        }
    }
    cout << fixed << setprecision(6) << max(l1, l2) << endl;
    return 0;
}