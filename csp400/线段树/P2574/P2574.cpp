#include <cstdio>
#include <iostream>

using namespace std;
const int maxn = 2e5 + 5;

struct node
{
    int l, r, lz;
    int sum;
} tree[maxn * 4];
int n, m, op, x, y, k;
int a[maxn];

void push_down(int i)
{
    if (tree[i].lz != 0)
    {
        int l = i << 1, r = (i << 1) | 1;
        tree[l].lz = 1 - tree[l].lz; //lazy_tag下放到左右孩子
        tree[r].lz = 1 - tree[r].lz;
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[l].sum = (mid - tree[l].l + 1) - tree[l].sum; //左右孩子节点更新区间和
        tree[r].sum = (tree[r].r - mid) - tree[r].sum;
        tree[i].lz = 0; //清空父亲节点lazy_tag
    }
}

void build_tree(int i, int l, int r)
{
    tree[i].l = l, tree[i].r = r;
    if (l == r)
    {
        tree[i].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(i << 1, l, mid);
    build_tree((i << 1) | 1, mid + 1, r);
    tree[i].sum = tree[i << 1].sum + tree[(i << 1) | 1].sum;
}

int search_tree(int i, int l, int r) //区间查询
{
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    if (tree[i].r < l || tree[i].l > r)
        return 0;
    if (tree[i].lz > 0)
        push_down(i);
    return search_tree(i << 1, l, r) + search_tree((i << 1) | 1, l, r);
}

void add2(int i, int l, int r) //区间修改
{
    if (tree[i].r <= r && tree[i].l >= l)
    {
        tree[i].sum = (tree[i].r - tree[i].l + 1) - tree[i].sum;
        tree[i].lz = 1 - tree[i].lz;
    }
    else
    {
        if (tree[i].lz > 0)
            push_down(i);
        if (tree[i << 1].r >= l)
            add2(i << 1, l, r);
        if (tree[(i << 1) | 1].l <= r)
            add2((i << 1) | 1, l, r);
        tree[i].sum = tree[i << 1].sum + tree[(i << 1) | 1].sum;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    a[1] = ch - '0';
    for (int i = 2; i <= n; i++)
        a[i] = getchar() - '0';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i];
    // }
    // cout << endl;
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if (!op)
            add2(1, x, y);
        else
            printf("%d\n", search_tree(1, x, y));
    }
    return 0;
}