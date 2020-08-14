#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct node
{
    int x, y, z;
} a[50005];

int n;

bool cmp(node a, node b)
{
    return a.z < b.z;
}

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
    return f == 1 ? x : -x;
}

inline double dis(int x, int y)
{
    return sqrt(1.0 * (a[x].x - a[y].x) * (a[x].x - a[y].x) + 1.0 * (a[x].y - a[y].y) * (a[x].y - a[y].y) + 1.0 * (a[x].z - a[y].z) * (a[x].z - a[y].z));
}

int main()
{
    freopen("in.txt", "r", stdin);
    n = read();
    for (int i = 0; i < n; i++)
        a[i].x = read(), a[i].y = read(), a[i].z = read();
    sort(a, a + n, cmp);
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += dis(i, i + 1);
    }
    printf("%.3lf\n", ans);
    return 0;
}