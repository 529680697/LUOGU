#include <iostream>

using namespace std;
typedef long long ll;
const int maxn = 1005;

struct node
{
    ll x, y, z;
} no[maxn];
int t, n;
ll r, h;
int father[maxn], root[maxn];

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
    }
}

inline bool adj(int a, int b)
{
    return ((r * r) << 2) >= ((no[a].x - no[b].x) * (no[a].x - no[b].x) + (no[a].y - no[b].y) * (no[a].y - no[b].y) + (no[a].z - no[b].z) * (no[a].z - no[b].z));
}

void init()
{
    for (int i = 0; i < maxn; i++)
    {
        father[i] = i;
        root[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        bool flag = false;
        cin >> n >> h >> r;
        init();
        for (int i = 0; i < n; i++)
            cin >> no[i].x >> no[i].y >> no[i].z;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (adj(i, j))
                    Union(i, j);
        for (int i = 0; i < n; i++)
        {
            int findfather = find_father(i);
            if (no[i].z <= r)
                root[findfather]++;
        }
        for (int i = 0; i < n; i++)
        {
            int findfather = find_father(i);
            if (no[i].z + r >= h && root[findfather] != 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
