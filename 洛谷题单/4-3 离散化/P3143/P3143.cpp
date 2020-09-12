// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e4 + 5;

int n, k, ans;
int a[maxn], f[maxn];

int main()
{
    int tmp;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int max_len = 0, max_begin = 0;
    for (int i = 0; i < n; i++)
        f[i] = upper_bound(a + i, a + n, a[i] + k) - a - i;
    for (int i = n; i >= 0; i--)
    {
        max_len = max(max_len, f[i] + f[i + f[i]]);
        f[i] = max(f[i], f[i + 1]);
    }
    cout << max_len << endl;
    return 0;
}