#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    int w, v;
    node(int _w, int _v) : w(_w), v(_v) {}
};

int n, m, dp[1004];
vector<node> g[1004];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int w, v, c, maxt = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v >> c;
        g[c].push_back(node(w, v));
        maxt = max(maxt, c);
    }
    for (int i = 1; i <= maxt; i++)
    {
        for (int v = m; v > 0; v--)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (v >= g[i][j].w)
                    dp[v] = max(dp[v], dp[v - g[i][j].w] + g[i][j].v);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}