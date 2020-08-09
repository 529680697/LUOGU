#include <cstdio>

using namespace std;
typedef long long ll;
const int maxn = 100005;

struct node
{
    int l, r;
    double sum, pf, lz;
} tree[maxn << 2];
int n, m, op, x, y;
double a[maxn], k;

void push_down(int i)
{
    if (tree[i].lz != 0)
    {
        int l = i << 1, r = (i << 1) | 1;
        tree[l].lz += tree[i].lz; //lazy_tag下放到左右孩子
        tree[r].lz += tree[i].lz;
        int mid = (tree[i].l + tree[i].r) >> 1;
        tree[l].pf += tree[i].lz * tree[l].sum * 2 + (mid - tree[l].l + 1) * tree[i].lz * tree[i].lz;
        tree[r].pf += tree[i].lz * tree[r].sum * 2 + (tree[r].r - mid) * tree[i].lz * tree[i].lz;
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
        tree[i].pf = a[l] * a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(i << 1, l, mid);
    build_tree((i << 1) | 1, mid + 1, r);
    tree[i].sum = tree[i << 1].sum + tree[(i << 1) | 1].sum;
    tree[i].pf = tree[i << 1].pf + tree[(i << 1) | 1].pf;
}

double search_a(int i, int l, int r) //查询和
{
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].sum;
    if (tree[i].r < l || tree[i].l > r)
        return 0;
    // if (tree[i].lz > 0)
    push_down(i);
    double ans = 0;
    if (tree[i << 1].r >= l)
        ans = search_a(i << 1, l, r);
    if (tree[i << 1 | 1].l <= r)
        ans += search_a(i << 1 | 1, l, r);
    return ans;
}

double search_pf(int i, int l, int r) //查询平方和
{
    if (tree[i].l >= l && tree[i].r <= r)
        return tree[i].pf;
    if (tree[i].r < l || tree[i].l > r)
        return 0;
    // if (tree[i].lz > 0)
    push_down(i);
    double ans = 0;
    if (tree[i << 1].r >= l)
        ans = search_pf(i << 1, l, r);
    if (tree[i << 1 | 1].l <= r)
        ans += search_pf(i << 1 | 1, l, r);
    return ans;
}

void add2(int i, int l, int r, double k) //区间修改
{
    if (tree[i].r < l || r < tree[i].l)
        return;
    if (tree[i].r <= r && tree[i].l >= l)
    {
        tree[i].pf += tree[i].sum * k * 2.0 + (tree[i].r - tree[i].l + 1) * k * k;
        tree[i].sum += k * (tree[i].r - tree[i].l + 1);
        tree[i].lz += k;
    }
    else
    {
        // if (tree[i].lz > 0)
        push_down(i);
        if (tree[i << 1].r >= l)
            add2(i << 1, l, r, k);
        if (tree[(i << 1) | 1].l <= r)
            add2((i << 1) | 1, l, r, k);
        tree[i].sum = tree[i << 1].sum + tree[(i << 1) | 1].sum;
        tree[i].pf = tree[i << 1].pf + tree[(i << 1) | 1].pf;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d%lf", &x, &y, &k);
            // printf("%.10lf\n", k);
            add2(1, x, y, k);
        }
        else if (op == 2)
        {
            scanf("%d%d", &x, &y);
            printf("%.4lf\n", search_a(1, x, y) / ((y - x + 1) * 1.0));
        }
        else
        {
            scanf("%d%d", &x, &y);
            double avg = search_a(1, x, y) / ((y - x + 1) * 1.0);
            printf("%.4lf\n", (search_pf(1, x, y) / ((y - x + 1) * 1.0)) - (avg * avg));
        }
    }

    return 0;
}