#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxm = 30;
const int maxv = 30005;

int n, m;
ll w[maxm], c[maxm], dp[maxv];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> w[i] >> c[i];
        c[i] *= w[i];
    }
    for (int i = 0; i < m; i++)
    {
        for (int v = n; v >= w[i]; v--)
        {
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}