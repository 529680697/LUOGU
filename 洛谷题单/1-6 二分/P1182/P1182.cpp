#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;

int n, m, a[maxn];

bool judge(int x)
{
    int tot = 0;
    int tmp_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > x)
            return false;
        tmp_sum += a[i];
        if (tmp_sum > x)
        {
            tmp_sum = a[i];
            tot++;
        }
    }
    if (tot >= m)
        return false;
    else
        return true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = 1e9, ans, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}