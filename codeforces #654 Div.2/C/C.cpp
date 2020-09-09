#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

ll t, a, b, m, n;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n >> m;
        if (min(a, b) >= m && a + b >= n + m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}