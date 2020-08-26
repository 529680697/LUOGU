#include <cstdio>

using namespace std;
typedef long long ll;
const int maxn = 100005;

struct node
{
    int l, r, lz;
    ll sum;
} tree[maxn * 4];
int n, m, op, x, y, k;
ll a[maxn];

void push_down(int i)
{
    if (tree[i].lz != 0)
    {
        int l = i << 1, r = (i << 1) | 1;
        tree[l].lz += tree[i].lz; //lazy_tag下放到左右孩子
        tree[r].lz += tree[i].lz;
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[l].sum += tree[i].lz * (mid - tree[l].l + 1); //左右孩子节点更新区间和
        tree[r].sum += tree[i].lz * (tree[r].r - mid);
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

ll search_tree(int i, int l, int r) //区间查询
{
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    if (tree[i].r < l || tree[i].l > r)
        return 0;
    if (tree[i].lz > 0)
        push_down(i);
    ll ans = 0;
    if (tree[i << 1].r >= l)
        ans += search_tree(i << 1, l, r);
    if (tree[((i << 1) | 1)].l <= r)
        ans += search_tree((i << 1) | 1, l, r);
    return ans;
}

void add2(int i, int l, int r, int k) //区间修改
{
    if (tree[i].r <= r && tree[i].l >= l)
    {
        tree[i].sum += k * (tree[i].r - tree[i].l + 1);
        tree[i].lz += k;
    }
    else
    {
        if (tree[i].lz > 0)
            push_down(i);
        if (tree[i << 1].r >= l)
            add2(i << 1, l, r, k);
        if (tree[(i << 1) | 1].l <= r)
            add2((i << 1) | 1, l, r, k);
        tree[i].sum = tree[i << 1].sum + tree[(i << 1) | 1].sum;
    }
}

int main()
{
    freopen("in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            add2(1, x, y, k);
        }
        else
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", search_tree(1, x, y));
        }
    }
    return 0;
}