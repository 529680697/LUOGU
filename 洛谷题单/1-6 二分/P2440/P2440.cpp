#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 100005;

ll n, k, a[maxn];

inline ll get_ans(int h)
{
    ll i = lower_bound(a, a + n, h) - a;
    ll ans = 0;
    for (int j = i; j < n; j++)
    {
        ans += a[j] / h;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ll l = 1, r = a[n - 1], ans, h;
    while (true)
    {
        h = (l + r) >> 1;
        ans = get_ans(h);
        if (l == h)
            break;
        if (ans < k)
            r = h;
        else
            l = h;
    }
    if (ans >= k)
        cout << h << endl;
    else
        cout << 0 << endl;
    return 0;
}