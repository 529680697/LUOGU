#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 100005;

struct node
{
    int l, r;
    char c;
} tree[maxn << 5];

int n, tot = 0;
int len[maxn], cnt = 0, rt[maxn];
char ch;

int read_num()
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
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

char read_char()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

void build_tree(int &rt, int last_rt, int l, int r, int pos)
{
    if (!rt)
        rt = ++tot;
    if (l == r)
    {
        tree[rt].c = ch;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        tree[rt].r = tree[last_rt].r, build_tree(tree[rt].l, tree[last_rt].l, l, mid, pos);
    else
        tree[rt].l = tree[last_rt].l, build_tree(tree[rt].r, tree[last_rt].r, mid + 1, r, pos);
}

char query(int rt, int l, int r, int pos)
{
    if (l == r)
        return tree[rt].c;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return query(tree[rt].l, l, mid, pos);
    else
        return query(tree[rt].r, mid + 1, r, pos);
}

int main()
{
    char op;
    int x;
    //freopen("in.txt", "r", stdin);
    n = read_num();
    for (int i = 0; i < n; i++)
    {
        op = read_char();
        switch (op)
        {
        case 'T':
            ch = read_char();
            ++cnt;
            len[cnt] = len[cnt - 1] + 1;
            build_tree(rt[cnt], rt[cnt - 1], 1, maxn, len[cnt]);
            break;
        case 'Q':
            x = read_num();
            printf("%c\n", query(rt[cnt], 1, maxn, x));
            break;
        case 'U':
            x = read_num();
            ++cnt;
            len[cnt] = len[cnt - x - 1];
            rt[cnt] = rt[cnt - x - 1];
            break;
        }
    }
    return 0;
}