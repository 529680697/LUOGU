#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1000005;

ll n, m, a[maxn], sum[maxn];

bool cmp(int a, int b)
{
    return a > b;
}

inline ll get_sum(ll h)
{
    ll i = lower_bound(a, a + n, h, greater<ll>()) - a - 1;
    // cout << h << " " << i << " ";
    ll tmp_sum = sum[i] - (i + 1) * h;
    // cout << tmp_sum << endl;
    return tmp_sum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, cmp);
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    ll low = 0, high = a[0], h, tmp_sum;
    while (true)
    {
        h = (low + high) >> 1;
        if (h == low)
            break;
        tmp_sum = get_sum(h);
        if (tmp_sum < m)
            high = h;
        else if (tmp_sum > m)
            low = h;
        else
            break;
        if (low > high)
            break;
    }
    cout << h << endl;
    return 0;
}