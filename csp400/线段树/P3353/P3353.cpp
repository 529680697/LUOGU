#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 100005;

struct node
{
    ll sum;
    int l, r, lz;
} tree[maxn * 4];

int n, w;
ll b[maxn];

inline void build_tree(int i, int l, int r)
{
    tree[i].l = l, tree[i].r = r;
    if (l == r)
    {
        // tree[i].sum += b[l];
    }
    else
    {
        int mid = (l + r) >> 1;
        build_tree(i << 1, l, mid);
        build_tree(i << 1 | 1, mid + 1, r);
        // tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
    }
}

inline void add(int i, int dis, int k) //单点修改
{
    if (tree[i].l == tree[i].r)
    {
        tree[i].sum += k;
    }
    else
    {
        if (dis <= tree[i << 1].r)
            add(i << 1, dis, k);
        else
            add(i << 1 | 1, dis, k);
        tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
    }
}

inline ll search(int i, int l, int r)
{
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    if (tree[i].l > r || tree[i].r < l)
        return 0;
    ll ans = 0;
    if (l <= tree[i << 1].r)
        ans = search(i << 1, l, r);
    if (tree[i << 1 | 1].l <= r)
        ans += search(i << 1 | 1, l, r);
    return ans;
}
int main()
{
    int x, tb, max_x = 0;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> w;
    build_tree(1, 1, maxn);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> tb;
        max_x = max(x, max_x);
        b[x] = tb;
        add(1, x, tb);
    }
    if (w == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i < max_x; i++)
    {
        ans = max(ans, search(1, i, i + w - 1));
    }
    cout << ans << endl;
    return 0;
}