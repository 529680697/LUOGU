#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

struct Line
{
    ll l, r, h;
    int mark;
} line[maxn << 1];

struct node
{
    int l, r, sum;
    ll len;
} tree[maxn << 2];

int n;
ll x[maxn << 1];

bool cmp(Line a, Line b)
{
    return a.h < b.h;
}

void build_tree(int i, int l, int r)
{
    tree[i].l = l, tree[i].r = r;
    tree[i].len = tree[i].sum = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build_tree(i << 1, l, mid);
    build_tree(i << 1 | 1, mid + 1, r);
}

void pushup(int i)
{
    int l = tree[i].l, r = tree[i].r;
    if (tree[i].sum)
        tree[i].len = x[r + 1] - x[l];
    else
        tree[i].len = tree[i << 1].len + tree[i << 1 | 1].len;
}

void update_tree(int i, ll L, ll R, int c)
{
    int l = tree[i].l, r = tree[i].r;
    if (x[r + 1] <= L || x[l] >= R)
        return;
    if (L <= x[l] && x[r + 1] <= R)
    {
        tree[i].sum += c;
        pushup(i);
        return;
    }
    update_tree(i << 1, L, R, c);
    update_tree(i << 1 | 1, L, R, c);
    pushup(i);
}

int main()
{
    int x_, y_, x__, y__;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x_ >> y_ >> x__ >> y__;
        x[(i << 1) - 1] = x_, x[i << 1] = x__;
        line[(i << 1) - 1] = {x_, x__, y_, 1};
        line[(i << 1)] = {x_, x__, y__, -1};
    }
    n <<= 1;
    sort(line + 1, line + n + 1, cmp);
    sort(x + 1, x + n + 1);
    int cnt = unique(x + 1, x + n + 1) - x - 1;
    build_tree(1, 1, cnt - 1);
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        update_tree(1, line[i].l, line[i].r, line[i].mark);
        ans += tree[1].len * (line[i + 1].h - line[i].h);
    }
    cout << ans << endl;
    return 0;
}