#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int t, n, r;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        ll ans = 0;
        ll num = min(n - 1, r);
        ans = (((1 + num) * num) >> 1);
        if (n <= r)
            ans++;
        cout << ans << endl;
    }

    return 0;
}