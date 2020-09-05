#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

int n, k, dp[maxn];
vector<int> t[maxn];

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a >> b;
        t[a].push_back(b);
    }
    for (int i = n; i > 0; i--)
    {
        if (t[i].size())
        {
            for (int j = 0; j < t[i].size(); j++)
                dp[i] = max(dp[i], dp[i + t[i][j]]);
        }
        else
            dp[i] = dp[i + 1] + 1;
    }
    cout << dp[1] << endl;
    return 0;
}