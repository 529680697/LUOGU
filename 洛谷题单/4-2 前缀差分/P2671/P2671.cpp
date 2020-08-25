#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
const int mod = 10007;

int n, m, num[maxn], color[maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
        cin >> color[i];
    int ans = 0;
    for (int i = 1; (i << 1) < n; i++)
        for (int j = i; j < n - i; j++)
            if (color[j - i] == color[j + i])
                ans = (ans + (j + j + 2) * (num[j - i] + num[j + i])) % mod;
    cout << ans << endl;
    return 0;
}