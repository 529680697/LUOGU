#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 1e7 + 5;

struct node
{
    int l, r, sum, lz;
} tree[maxn << 2];

int n, m;

inline int read()
{
    int x = 0, f = 1;
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
    }
}

void push_down(int i)
{
    if (tree[i].lz > 0)
    {
        int l = i << 1, r = l | 1;
        tree[l].lz += tree[i].lz;
        tree[r].lz += tree[i].lz;
        tree[l].sum += tree[i].lz * (tree[l].r - tree[l].l + 1);
        tree[r].sum += tree[i].lz * (tree[r].r - tree[r].l + 1);
        tree[i].lz = 0;
    }
}

void add(int i, int l, int r, int k)
{
    if (l <= tree[i].r && tree[i].r <= r)
    {
        tree[i].lz += k;
        tree[i].sum += k * (tree[i].r - tree[i].l + 1);
    }
    else
    {
        push_down(i);
        if (tree[i << 1].r >= l)
            add(i << 1, l, r, k);
        if (tree[i << 1 | 1].l <= r)
            add(i << 1 | 1, l, r, k);
        tree[i].sum = tree[i << 1].sum + tree[i << 1 | 1].sum;
    }
}

int search(int i, int l, int r)
{
    if (tree[i].l > r || tree[i].r < l)
        return 0;
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    push_down(i);
    int ans = 0;
    if (tree[i << 1].r >= l)
        ans += search(i << 1, l, r);
    if (tree[i << 1 | 1].l <= r)
        ans += search(i << 1 | 1, l, r);
    return ans;
}

int main()
{
    int op, a, b;
    // ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    n = read(), m = read();
    build(1, 1, n);
    while (m--)
    {
        op = read();
        if (op)
        {
            a = read();
            printf("%d\n", search(1, a, a));
        }
        else
        {
            a = read(), b = read();
            add(1, a, b, 1);
        }
    }

    return 0;
}