#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef unsigned long long ll;

int n, a, b;
ll c[55][55], ans;

void init()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i < 51; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    init();
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
        {
            // ans += c[n][i] * c[n - i][j];
            for (int k = 0; k <= min(i, j); k++)
            {
                ans += c[n][i - k] * c[n - i + k][j - k] * c[n - i - j + k + k][k];
            }
        }

    cout << ans << endl;
    return 0;
}