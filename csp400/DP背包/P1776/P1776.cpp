#include <iostream>
#include <algorithm>

using namespace std;
const int maxv = 40005;
const int maxn = 100005;

int n, V;
int dp[maxv], w[maxn], c[maxn];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int a, b, num, k = 0;
    cin >> n >> V;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> num;
        for (int j = 1; j <= num; j <<= 1)
        {
            c[k] = a * j;
            w[k++] = b * j;
            num -= j;
        }
        if (num)
        {
            c[k] = a * num;
            w[k++] = b * num;
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int v = V; v >= w[i]; v--)
        {
            dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}