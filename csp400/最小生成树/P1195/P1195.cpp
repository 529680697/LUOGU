#include <iostream>
#include <algorithm>

using namespace std;
const int maxe = 10005;
const int maxn = 1005;

struct node
{
    int u, v;
    int w;
} e[maxe];

int n, m, k;
int fa[maxn];

bool cmp(node a, node b)
{
    return a.w < b.w;
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
        fa[a] = x;
    }
    return x;
}

int kruskal()
{
    int ans = 0, edge_num = 0;
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
    }
    sort(e, e + m, cmp);
    for (int i = 0; i < m; i++)
    {
        int fu = find_fa(e[i].u);
        int fv = find_fa(e[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ans += e[i].w;
            edge_num++;
            if (edge_num == n - k)
                break;
        }
    }
    if (edge_num != n - k)
        return -1;
    else
        return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    int ans = kruskal();
    if (ans == -1)
        cout << "No Answer" << endl;
    else
        cout << ans << endl;
    return 0;
}