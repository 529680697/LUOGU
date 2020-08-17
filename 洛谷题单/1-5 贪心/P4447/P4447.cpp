#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, a[maxn];
int q[maxn], sum[maxn], cur;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    fill(q, q + maxn, inf);
    // cout << lower_bound(q, q + n, 1) - q;
    q[0] = a[0], sum[0] = 1, cur = 1;
    for (int i = 1; i < n; i++)
    {
        int pos = lower_bound(q, q + n, a[i] - 1) - q;
        if (q[pos] == a[i] - 1)
        {
            while (q[pos + 1] == a[i] - 1)
                pos++;
            sum[pos]++;
            q[pos]++;
        }
        else
        {
            q[cur] = a[i];
            sum[cur++] = 1;
        }
    }
    int ans = inf;
    for (int i = 0; i < cur; i++)
    {
        ans = min(ans, sum[i]);
    }
    cout << ans << endl;
    return 0;
}