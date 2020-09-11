// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 55;

string s;
int dp[maxn][maxn];

int dfs(int l, int r)
{
    if (dp[l][r])
        return dp[l][r];
    if (l == r)
        return dp[l][r] = 1;
    if (s[l] == s[r])
        return dp[l][r] = min(dfs(l + 1, r), dfs(l, r - 1));
    dp[l][r] = inf;
    for (int i = l; i < s.length() - 1; i++)
        dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i + 1, r));
    return dp[l][r];
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cin.tie(nullptr);
    cin >> s;
    cout << dfs(0, s.length() - 1) << endl;
    return 0;
}