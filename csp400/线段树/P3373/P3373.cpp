#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

struct node
{
    int l, r;
    ll mlz, plz, sum;
} tree[maxn << 2];

int n, m, p;
ll a[maxn];

void build_tree(int i, int l, int r)
{
    tree[i].l = l, tree[i].r = r;
    tree[i].mlz = 1;
    if (l == r)
        tree[i].sum = a[l] % p;
    else
    {
        int mid = (l + r) >> 1;
        build_tree(i << 1, l, mid);
        build_tree(i << 1 | 1, mid + 1, r);
        tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % p;
    }
}

void push_down(int i)
{
    ll mlz = tree[i].mlz, plz = tree[i].plz;
    tree[i << 1].sum = (tree[i << 1].sum * mlz + plz * (tree[i << 1].r - tree[i << 1].l + 1)) % p;
    tree[i << 1 | 1].sum = (tree[i << 1 | 1].sum * mlz + plz * (tree[i << 1 | 1].r - tree[i << 1 | 1].l + 1)) % p;
    tree[i << 1].mlz = (tree[i << 1].mlz * mlz) % p;
    tree[i << 1 | 1].mlz = (tree[i << 1 | 1].mlz * mlz) % p;
    tree[i << 1].plz = (tree[i << 1].plz * mlz + plz) % p;
    tree[i << 1 | 1].plz = (tree[i << 1 | 1].plz * mlz + plz) % p;
    tree[i].plz = 0;
    tree[i].mlz = 1;
}

void add(int i, int l, int r, ll k)
{
    if (tree[i].r < l || tree[i].l > r)
        return;
    if (l <= tree[i].l && tree[i].r <= r)
    {
        tree[i].sum += (k * (tree[i].r - tree[i].l + 1)) % p;
        tree[i].plz = (tree[i].plz + k) % p;
    }
    else
    {
        push_down(i);
        if (l <= tree[i << 1].r)
            add(i << 1, l, r, k);
        if (tree[i << 1].r < r)
            add(i << 1 | 1, l, r, k);
        tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % p;
    }
}

void mul(int i, int l, int r, ll k)
{
    if (tree[i].r < l || tree[i].l > r)
        return;
    if (l <= tree[i].l && tree[i].r <= r)
    {
        tree[i].sum = (tree[i].sum * k) % p;
        tree[i].plz = (tree[i].plz * k) % p;
        tree[i].mlz = (tree[i].mlz * k) % p;
    }
    else
    {
        push_down(i);
        if (l <= tree[i << 1].r)
            mul(i << 1, l, r, k);
        if (tree[i << 1].r < r)
            mul(i << 1 | 1, l, r, k);
        tree[i].sum = (tree[i << 1].sum + tree[i << 1 | 1].sum) % p;
    }
}

ll search(int i, int l, int r)
{
    if (tree[i].r < l || tree[i].l > r)
        return 0;
    if (l <= tree[i].l && tree[i].r <= r)
        return tree[i].sum;
    else
    {
        push_down(i);
        ll ans = 0;
        if (l <= tree[i << 1].r)
            ans += search(i << 1, l, r) % p;
        if (tree[i << 1].r < r)
            ans += search(i << 1 | 1, l, r) % p;
        return ans % p;
    }
}

int main()
{
    int op, l, r, k;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> l >> r >> k;
            mul(1, l, r, k);
            break;
        case 2:
            cin >> l >> r >> k;
            add(1, l, r, k);
            break;
        case 3:
            cin >> l >> r;
            cout << search(1, l, r) << endl;
            break;
        }
    }
    return 0;
}