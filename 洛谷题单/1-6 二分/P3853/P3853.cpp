#include <iostream>

using namespace std;
const int maxn = 100005;

int d, n, m, a[maxn];

bool judge(int x)
{
    int tot = 0; //新增路标计数
    int cur = 0; //当前路标坐标
    for (int i = 0; i < n;)
    {
        if (a[i] - cur > x)
        {
            tot++;
            cur += x;
        }
        else
        {
            cur = a[i++];
        }
    }
    if (tot <= m)
        return true;
    else
        return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> d >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 1, r = a[n - 1], ans, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}