#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6;

int n, p, a[maxn];
long long ans[maxn], cnt;

int f(int x)
{
    int flag = 0;
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        while (a[flag] <= x + i && flag < n)
            ++flag;
        ans = ans * (flag - i) % p;
    }
    return ans;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int minn = 0;
    for (int i = 0; i < n; i++)
        minn = max(minn, a[i] - i);
    for (int i = minn; i <= 2000; i++)
        if (f(i))
            ans[cnt++] = i;
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
        cout << ans[i] << " ";
    return 0;
}