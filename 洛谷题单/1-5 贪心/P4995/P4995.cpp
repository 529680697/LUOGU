#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
ll a[305];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            ans += (a[cur] - a[n + 1 - cur]) * (a[cur] - a[n + 1 - cur]);
            cur = n + 1 - cur;
        }
        else
        {
            ans += (a[n - cur] - a[cur]) * (a[n - cur] - a[cur]);
            cur = n - cur;
        }
    }
    cout << ans << endl;
    return 0;
}