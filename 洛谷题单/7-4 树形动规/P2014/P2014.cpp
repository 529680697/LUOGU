#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 305;

int n, m, wi[maxn], dp[maxn][maxn][maxn], ans[maxn][maxn][maxn];
vector<int> adj[maxn];

int get_sum(int x, int k, int sum);

int dfs(int x, int k, int sum)
{
    if (dp[x][k][sum])
        return dp[x][k][sum];
    if (sum == 0 || k == 0 || adj[x].size() == 0)
        return 0;
    int v = adj[x][k - 1];
    if (k == 1)
        dp[x][k][sum] = get_sum(v, adj[v].size(), sum);
    for (int i = 0; i <= sum; i++)
    {
        int tmpa = dfs(x, k - 1, i);
        int tmpb = get_sum(v, adj[v].size(), sum - i);
        dp[x][k][sum] = max(dp[x][k][sum], tmpa + tmpb);
    }
    return dp[x][k][sum];
}

int get_sum(int x, int k, int sum)
{
    if (ans[x][k][sum])
        return ans[x][k][sum];
    if (sum == 0)
        return 0;
    else if (sum == 1)
        return ans[x][k][sum] = wi[x];
    if (k == 0)
        return ans[x][k][sum] = wi[x];
    int v = adj[x][k - 1];
    for (int i = 0; i < sum; i++)
    {
        int tmpa = dfs(x, k - 1, i);
        int tmpb = get_sum(v, adj[v].size(), sum - i - 1);
        ans[x][k][sum] = max(ans[x][k][sum], tmpa + tmpb);
    }
    return ans[x][k][sum] += wi[x];
}

int main()
{
    int v;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    auto a = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> wi[i];
        adj[v].push_back(i);
    }
    cout << get_sum(0, adj[0].size(), m + 1);
    return 0;
}
