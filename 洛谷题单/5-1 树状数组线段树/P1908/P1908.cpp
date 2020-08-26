#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXN = 5e5 + 5;

struct node
{
    int val, pos;
} tmp[MAXN];

int n, m;
int a[MAXN];
int c[MAXN];

bool cmp(node a, node b)
{
    return a.val < b.val;
}

int lowbit(int x)
{
    return x & -x;
}

void add(int i, int k)
{
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int r = 0;
    while (i > 0)
    {
        r += c[i];
        i -= lowbit(i);
    }
    return r;
}

inline int get_num()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x;
}

int main()
{
    freopen("in", "r", stdin);
    n = get_num();
    for (int i = 0; i < n; i++)
    {
        tmp[i].val = get_num();
        tmp[i].pos = i;
    }
    sort(tmp, tmp + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || tmp[i].val != tmp[i - 1].val)
            a[tmp[i].pos] = i + 1;
        else
            a[tmp[i].pos] = a[tmp[i - 1].pos];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        add(a[i], 1);
        ans += sum(n) - sum(a[i]);
    }
    cout << ans << endl;
    return 0;
}