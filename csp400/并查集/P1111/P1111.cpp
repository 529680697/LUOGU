#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
const int maxn = 1005;
const int maxm = 100005;

struct node
{
    int x, y, t;
} no[maxm];

int n, m, p;
int father[maxn];
set<int> s;

bool cmp(node a, node b)
{
    return a.t < b.t;
}

int find_father(int x)
{
    int a = x;
    while (x != father[x])
    {
        x = father[x];
    }
    while (a != father[a])
    {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b)
{
    a = find_father(a);
    b = find_father(b);
    if (a != b)
    {
        father[a] = b;
        s.erase(a);
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
        s.insert(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    bool flag = false;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        cin >> no[i].x >> no[i].y >> no[i].t;
    }
    sort(no, no + m, cmp);
    for (int i = 0; i < m; i++)
    {
        Union(no[i].x, no[i].y);
        if (s.size() == 1)
        {
            cout << no[i].t << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << -1 << endl;
    return 0;
}