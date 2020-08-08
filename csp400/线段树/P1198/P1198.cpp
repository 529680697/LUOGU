#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const ll INF = (1 << 30);

struct node
{
    int l, r;
    ll ans;
} tree[maxn << 2];

ll m, d, t = 0, n;
int len = 0;

inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void build(int i, int l, int r)
{
    tree[i].l = l, tree[i].r = r;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        tree[i].ans = -INF;
        // tree[i].ans = max(tree[i << 1].ans, tree[i << 1 | 1].ans);
    }
}

void add(int i, int dis, ll k)
{
    if (tree[i].l == tree[i].r)
        tree[i].ans = k;
    else
    {
        if (dis <= tree[i << 1].r)
            add(i << 1, dis, k);
        else
            add(i << 1 | 1, dis, k);
        tree[i].ans = max(tree[i << 1].ans, tree[i << 1 | 1].ans);
    }
}

ll search_tree(int i, int l, int r)
{
    if (l <= tree[i].l && tree[i].r <= r)
        return tree[i].ans;
    if (tree[i].r < l || r < tree[i].l)
        return 0;
    ll a = -INF, b = -INF;
    if (l <= tree[i << 1].r)
        a = search_tree(i << 1, l, r);
    if (tree[i << 1 | 1].l <= r)
        b = search_tree(i << 1 | 1, l, r);
    return max(a, b);
}

int main()
{
    char op;
    freopen("in.txt", "r", stdin);
    m = read(), d = read();
    // cout << m << d << endl;
    build(1, 1, 2e5);
    for (int i = 0; i < m; i++)
    {
        cin >> op;
        n = read();
        if (op == 'A')
        {
            n = (n + t) % d;
            add(1, ++len, n);
        }
        else
        {
            if (n == 0)
                t = 0;
            else
                t = search_tree(1, len - n + 1, len);
            printf("%lld\n", t);
        }
    }
    return 0;
}