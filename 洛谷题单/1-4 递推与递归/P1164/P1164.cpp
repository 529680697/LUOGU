#include <iostream>

using namespace std;

int n, m, a[105];

int dfs(int x, int sum)
{
    if (sum == 0)
        return 1;
    else if (sum < 0)
        return 0;
    if (x == n)
        return 0;
    int ans = 0;
    if (sum >= a[x])
        ans += dfs(x + 1, sum - a[x]);
    ans += dfs(x + 1, sum);
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs(0, m) << endl;
    return 0;
}