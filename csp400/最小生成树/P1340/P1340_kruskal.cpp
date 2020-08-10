#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 205;
const int maxm = 6005 << 1;
const int inf = 0x3f3f3f3f;

struct node
{
    int u, v, w, id;
    bool use, in;
} no[maxm];

int n, m, fa[maxn], an[maxm];

bool cmp(node a, node b)
{
    return a.w < b.w;
}

inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    x = x * f;
}

int find_fa(int x)
{
    int a = x;
    while (x != fa[x])
        x = fa[x];
    while (a != fa[a])
    {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

int kurskal()
{
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
        no[i].in = false;
    for (int i = 0; i < m; i++)
    {
        int fu = find_fa(no[i].u);
        int fv = find_fa(no[i].v);
        if (fu != fv && no[i].use)
        {
            fa[fu] = fv;
            ans += no[i].w;
            cnt++;
            no[i].in = true;
            if (cnt == n - 1)
                break;
        }
    }
    if (cnt < n - 1)
        return -1;
    else
        return ans;
}

int main()
{
    int a, b, c;
    freopen("in.txt", "r", stdin);
    read(n), read(m);
    for (int i = 0; i < m; i++)
    {
        read(a), read(b), read(c);
        no[i].u = a, no[i].v = b, no[i].w = c;
        no[i].use = true;
        no[i].id = i;
    }
    sort(no, no + m, cmp);
    an[m - 1] = kurskal();
    for (int i = m - 2; i >= 0; i--)
    {
        if (i < n - 2)
        {
            an[i] = -1;
            continue;
        }
        int j = 0;
        for (; j < m; j++)
        {
            if (no[j].id == i + 1)
            {
                no[j].use = false;
                break;
            }
        }
        if (no[j].in)
            an[i] = kurskal();
        else
            an[i] = an[i + 1];
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", an[i]);
    return 0;
}