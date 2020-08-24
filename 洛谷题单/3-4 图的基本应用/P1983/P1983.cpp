#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct node
{
    int v, dep;
    node() {}
    node(int _v, int _dep) : v(_v), dep(_dep) {}
};

int n, m, indegree[1005];
bool in[1005], g[1005][1005];

int to_pol_sort()
{
    queue<node> q;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (g[i][j])
                indegree[j]++;
        }
        if (indegree[j] == 0)
            q.push(node(j, 1));
    }
    int cur_dep = 0;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        cur_dep = now.dep;
        for (int i = 1; i <= n; i++)
        {
            if (g[now.v][i])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(node(i, cur_dep + 1));
            }
        }
    }
    return cur_dep;
}

int main()
{
    int a, tmp, begin, end;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> begin;
        memset(in, 0, sizeof(in));
        in[begin] = true;
        for (int j = 1; j < a - 1; j++)
        {
            cin >> tmp;
            in[tmp] = true;
        }
        cin >> end;
        in[end] = true;
        for (int j = begin; j <= end; j++)
            if (in[j])
                for (int k = begin + 1; k < end; k++)
                    if (!in[k])
                        g[j][k] = true;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << to_pol_sort() << endl;
    return 0;
}