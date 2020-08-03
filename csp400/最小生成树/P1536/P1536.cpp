#include <iostream>

using namespace std;
const int maxn = 1005;

int n, m;
int fa[maxn];
bool root[maxn];

int find_fa(int x)
{
    int a = x;
    while (x != fa[x])
    {
        x = fa[x];
    }
    while (a != fa[a])
    {
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int a, int b)
{
    a = find_fa(a);
    b = find_fa(b);
    if (a != b)
        fa[a] = b;
}

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        fa[i] = i;
        root[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int a, b;
    cin >> n >> m;
    while (n)
    {
        init();
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            Union(a, b);
        }
        for (int i = 1; i <= n; i++)
        {
            root[find_fa(i)] = true;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (root[i])
                ans++;
        }
        cout << ans - 1 << endl;
        cin >> n >> m;
    }
    return 0;
}