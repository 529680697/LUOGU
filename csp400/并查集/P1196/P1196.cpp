#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 30005;

int t, a, b, fa[maxn], pos[maxn];
char c;
vector<int> v[maxn], tmp;

void init()
{
    for (int i = 1; i < maxn; i++)
    {
        fa[i] = i;
        v[i].push_back(i);
        pos[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> t;
    init();
    for (int i = 0; i < t; i++)
    {
        cin >> c >> a >> b;
        if (c == 'M')
        {
            int faa = fa[a], fab = fa[b];
            for (vector<int>::iterator it = v[faa].begin(); it != v[faa].end(); it++)
            {
                pos[*it] = v[fab].size();
                v[fab].push_back(*it);
                fa[*it] = fab;
            }
            vector<int>().swap(v[faa]);
        }
        else
        {
            if (fa[a] == fa[b])
            {
                cout << abs(pos[a] - pos[b]) - 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
