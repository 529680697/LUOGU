#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e3 + 5;

struct node
{
    int a, b;
    bool operator<(const node &x) const
    {
        if (a == x.a)
            return x.b < b;
        return x.a < a;
    }
} no[maxn];

int n, dp[maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> no[i].a >> no[i].b;
    sort(no + 1, no + n + 1);
    int len = 1;
    dp[1] = no[1].b;
    for (int i = 1; i <= n; i++)
    {
        if (no[i].b > dp[len])
            dp[++len] = no[i].b;
        else
        {
            int j = lower_bound(dp + 1, dp + 1 + len, no[i].b) - dp;
            dp[j] = no[i].b;
        }
    }
    cout << len << endl;
    return 0;
}