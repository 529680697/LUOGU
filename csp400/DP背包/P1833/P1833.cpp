#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100005;

int n, sh, sm, eh, em; //开始和最晚结束时间
int v, C[maxn], T[maxn], dp[1005], cnt;

int main()
{
    // ios::sync_with_stdio(false);
    int t, c, p;
    freopen("in.txt", "r", stdin);
    cin >> sh;
    getchar();
    cin >> sm >> eh;
    getchar();
    cin >> em >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &t, &c, &p);
        if (p)
        {
            int j;
            for (j = 1; j <= p; j <<= 1)
            {
                C[cnt] = c * j;
                T[cnt++] = t * j;
                p -= j;
            }
            if (p)
            {
                C[cnt] = c * p;
                T[cnt++] = t * p;
            }
        }
        else
        {
            int j;
            for (j = 1; j < 1000; j <<= 1)
            {
                C[cnt] = c * j;
                T[cnt++] = t * j;
            }
        }
    }
    v += 60 * (eh - sh) + em - sm;
    // cout << v << endl;
    for (int i = 0; i < cnt; i++)
    {
        for (int j = v; j >= T[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - T[i]] + C[i]);
        }
    }
    cout << dp[v] << endl;
    return 0;
}