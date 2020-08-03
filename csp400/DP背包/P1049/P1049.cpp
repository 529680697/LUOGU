#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 35;
const int maxv = 20005;
int v, n;
int a[maxn], dp[maxv];

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> v >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = v; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << v - dp[v] << endl;
    return 0;
}