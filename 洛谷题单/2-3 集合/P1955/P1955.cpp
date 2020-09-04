#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

struct node
{
    int a, b;
    bool e;
    bool operator<(const node &a) const
    {
        return a.e < e;
    }
} tmp[maxn];

int t, n, a[maxn << 1], fa[maxn << 1];

int find_fa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find_fa(fa[x]);
}

void Union(int x, int y)
{
    x = find_fa(x), y = find_fa(y);
    if (x != y)
        fa[x] = y;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < maxn * 2; i++)
        {
            fa[i] = i;
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            cin >> tmp[i].a >> tmp[i].b >> tmp[i].e;
            a[j++] = tmp[i].a, a[j++] = tmp[i].b;
        }
        sort(tmp, tmp + n);
        sort(a, a + 2 * n);
        int unq_num = unique(a, a + 2 * n) - a;
        // for (int i = 0; i < 2 * n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << unq_num << endl;
        int flag = true;
        for (int i = 0; i < n; i++)
        {
            int x = lower_bound(a, a + unq_num, tmp[i].a) - a;
            int y = lower_bound(a, a + unq_num, tmp[i].b) - a;
            // cout << x << " " << y << endl;
            if (tmp[i].e)
                Union(x, y);
            else
            {
                if (find_fa(x) == find_fa(y))
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}