#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxall = 100007;
const int maxn = 1005;
int n, all, q;
int c[maxn], w[maxn], num, dp[maxn][maxall], flag[maxall];
int C[maxall], W[maxall];

int main()
{
    int ask_num, price;
    freopen("in.txt", "r", stdin);
    // fill(dp[0], dp[0] + maxn * maxall, 0);
    // cin >> n;
    scanf("%d", &n);
    all = 0;
    for (int i = 0; i < n; i++)
    {
        // cin >> w[i] >> c[i] >> num;
        scanf("%d%d%d", &w[i], &c[i], &num);
        for (int k = 0; k < num; k++)
        {
            C[all + k] = c[i];
            W[all + k] = w[i];
            flag[all + k] = i;
        }
        all += num;
    }
    // for (int i = 0; i < all; i++)
    // {
    //     cout << C[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < all; i++)
    // {
    //     cout << W[i] << " ";
    // }
    for (int l = 0; l < n; l++)
    {
        for (int i = 0; i < all; i++)
        {
            if (flag[i] != l)
            {
                for (int v = maxn; v >= W[i]; v--)
                {
                    dp[l][v] = max(dp[l][v], dp[l][v - W[i]] + C[i]);
                }
            }
        }
    }
    // cin >> q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        // cin >> ask_num >> price;
        scanf("%d%d", &ask_num, &price);
        // cout << dp[ask_num][price] << endl;
        printf("%d\n", dp[ask_num][price]);
    }
    return 0;
}