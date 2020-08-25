#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[1005][1005];

int main()
{
    int x0, y0, x1, y1;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x0 >> y0 >> x1 >> y1;
        a[x0][y0]++;
        a[x1 + 1][y0]--;
        a[x0][y1 + 1]--;
        a[x1 + 1][y1 + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}