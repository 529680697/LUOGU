#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 5005;
const int inf = 0x3f3f3f3f;

// struct node
// {
//     int v, w;
//     node() {}
//     node(int _v) : v(_v), w(-1) {}
// };

// int n, m, d[maxn], num[maxn];
// vector<node> adj[maxn];
// set<int> pre[maxn];
// bool inq[maxn], not_end[maxn];

// void spfa(int s)
// {
//     memset(inq, 0, sizeof(inq));
//     memset(num, 0, sizeof(num));
//     fill(d, d + maxn, inf);
//     for (int i = 0; i < maxn; i++)
//         pre[i].clear();
//     queue<int> q;
//     q.push(s);
//     inq[s] = true;
//     d[s] = 0;
//     num[s] = 1;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         inq[u] = false;
//         for (int j = 0; j < adj[u].size(); j++)
//         {
//             int v = adj[u][j].v;
//             int w = adj[u][j].w;
//             if (d[u] + w < d[v])
//             {
//                 d[v] = d[u] + w;
//                 num[v] = num[u];
//                 pre[v].clear();
//                 pre[v].insert(u);
//                 if (!inq[v])
//                 {
//                     q.push(v);
//                     inq[v] = true;
//                 }
//             }
//             else if (d[u] + w == d[v])
//             {
//                 pre[v].insert(u);
//                 num[v] = 0;
//                 for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++)
//                     num[v] = (num[v] + num[*it]) % 80112002;
//             }
//         }
//     }
// }

int n, m, num[maxn];
vector<int> adj[maxn];
bool not_end[maxn];

int get_num(int x)
{
    if (num[x])
        return num[x];
    for (int i = 0; i < adj[x].size(); i++)
    {
        num[x] = (num[x] + get_num(adj[x][i])) % 80112002;
    }
    if (num[x] == 0)
        num[x] = 1;
    return num[x];
}

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
        not_end[a] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!not_end[i])
        {
            ans = (ans + get_num(i)) % 80112002;
        }
    }
    cout << ans << endl;
    // vector<int> s, e;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (!inq[i])
    //         s.push_back(i);
    //     if (!not_end[i])
    //         e.push_back(i);
    // }
    // int ans = 0;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     spfa(s[i]);
    //     for (int j = 0; j < e.size(); j++)
    //         ans = (ans + num[e[j]]) % 80112002;
    // }
    // cout << ans << endl;
    return 0;
}