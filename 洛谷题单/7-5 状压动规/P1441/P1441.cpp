// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 22;

int n, m, w[maxn];

int num_count(int x)
{
    int num = 0;
    for (int i = 0; i < n; i++)
        if ((x >> i) & 1)
            num++;
    return num;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    int ans = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        if (num_count(i) == n - m)
        {
            bitset<2010> b;
            b[0] = 1;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1)
                    b |= b << w[j];
            ans = max(ans, (int)b.count());
        }
    }
    cout << ans - 1 << endl;
    return 0;
}