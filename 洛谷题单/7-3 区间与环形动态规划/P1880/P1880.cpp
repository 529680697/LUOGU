#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;

int n, a[maxn], dpmin[maxn][maxn], dpmax[maxn][maxn], sum[maxn];

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            sum[0] = a[0];
        else
            sum[i] = sum[i - 1] + a[i];
    }

    // for (int i = 0; i < n; i++)
    //     dpmin[i][i] = dpmax[i][i] = a[i];
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = (i + l - 1) % n;
            int tmpmin = inf, tmpmax = 0;
            for (int num = 0; num < l - 1; num++)
            {
                tmpmin = min(tmpmin, dpmin[i][(i + num) % n] + dpmin[(i + num + 1) % n][j]);
                tmpmax = max(tmpmax, dpmax[i][(i + num) % n] + dpmax[(i + num + 1) % n][j]);
            }
            int all = 0;
            if (j >= i)
            {
                if (i == 0)
                    all = sum[j];
                else
                    all = sum[j] - sum[i - 1];
            }
            else
                all = sum[j] + sum[n - 1] - sum[i - 1];
            dpmax[i][j] = all + tmpmax;
            dpmin[i][j] = all + tmpmin;
        }
    }
    int tmpmin = inf, tmpmax = 0;
    for (int i = 0; i < n; i++)
    {
        tmpmax = max(tmpmax, dpmax[i][(i + n - 1) % n]);
        tmpmin = min(tmpmin, dpmin[i][(i + n - 1) % n]);
    }
    cout << tmpmin << endl;
    cout << tmpmax << endl;
    return 0;
}