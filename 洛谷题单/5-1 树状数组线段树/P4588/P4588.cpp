#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 100005;

struct node
{
    int l, r;
    ll sum;
} tree[maxn * 4];
int m, op, q, mod;

void build_tree(int i, int l, int r)
{
    tree[i].l = l, tree[i].r = r;
    if (l == r)
    {
        tree[i].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(i << 1, l, mid);
    build_tree((i << 1) | 1, mid + 1, r);
    tree[i].sum = (tree[i << 1].sum * tree[(i << 1) | 1].sum) % mod;
}

void add(int i, int pos, int k) //单点修改
{
    if (tree[i].r == tree[i].l)
    {
        tree[i].sum = k % mod;
    }
    else
    {
        int mid = (tree[i].r + tree[i].l) >> 1;
        if (mid >= pos)
            add(i << 1, pos, k);
        else
            add((i << 1) | 1, pos, k);
        tree[i].sum = (tree[i << 1].sum * tree[(i << 1) | 1].sum) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> q >> mod;
        build_tree(1, 1, q);
        for (int i = 1; i <= q; i++)
        {
            cin >> op >> m;
            if (op == 1)
            {
                add(1, i, m);
                cout << tree[1].sum % mod << endl;
            }
            else
            {
                add(1, i, 1);
                add(1, m, 1);
                cout << tree[1].sum % mod << endl;
            }
        }
    }
    return 0;
}