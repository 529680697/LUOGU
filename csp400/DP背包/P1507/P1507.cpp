#include <iostream>
#include <algorithm>

using namespace std;

const int maxv = 500;

int wv, vv, n;
int dp[maxv][maxv], v[maxv], w[maxv], c[maxv];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> vv >> wv >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int _w = wv; _w >= w[i]; _w--)
        {
            for (int _v = vv; _v >= v[i]; _v--)
            {
                dp[_w][_v] = max(dp[_w][_v], dp[_w - w[i]][_v - v[i]] + c[i]);
            }
        }
    }
    cout << dp[wv][vv] << endl;
    return 0;
}