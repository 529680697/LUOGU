#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 305;

int t, n, k;
bool g[maxn][maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        fill(g[0], g[0] + maxn * maxn, false);
        if (k % n == 0)
            cout << 0 << endl;
        else
            cout << 2 << endl;
        for (int i = 0; i < n && k; i++)
        {
            for (int j = i, cou = 0; cou < n && k; cou++, j = (j + 1) % n)
            {
                k--;
                g[cou][j] = true;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << g[i][j];
            cout << endl;
        }
    }
    return 0;
}