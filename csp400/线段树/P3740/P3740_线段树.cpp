#include <iostream>

using namespace std;
const int maxn = 10000005;
const int maxm = 1005;

int n, m, x[maxm], y[maxm], ans = 0;
bool covered[maxn << 2];

bool add(int i, int l, int r, int L, int R)
{
    if (covered[i])
        return true;
    if (l <= L && R <= r && !covered[i])
    {
        covered[i] = true;
        return false;
    }
    int mid = (L + R) >> 1;
    bool haveCovered1 = true, haveCovered2 = true;
    if (l <= mid)
        haveCovered1 = add(i << 1, l, r, L, mid);
    if (mid < r)
        haveCovered2 = add(i << 1 | 1, l, r, mid + 1, R);
    covered[i] = covered[i << 1] & covered[i << 1 | 1];
    return haveCovered1 && haveCovered2;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> x[i] >> y[i];
    for (int i = m - 1; i >= 0; i--)
        if (!add(1, x[i], y[i], 1, n))
            ans++;
    cout << ans << endl;
    return 0;
}