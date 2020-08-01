#include <iostream>

using namespace std;
const int maxn = 5005;

int n, m, p;
int father[maxn];

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

void init()
{
    for (int i = 1; i <= n; i++)
        father[i] = i;
}

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    cin >> n >> m >> p;
    init();
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Union(a, b);
    }
    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        if (find_father(a) == find_father(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}