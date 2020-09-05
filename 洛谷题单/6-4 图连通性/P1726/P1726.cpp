#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e3 + 5;
const int maxm = 5e4 + 5;

struct node
{
    int v, nxt;
} edge[maxm << 1];

int n, m, head[maxn], total;
int low[maxn], dfn[maxn], times;         //回溯数组、时间戳数组、总时间
int cnt, color[maxn], count_color[maxn]; //强连通分量编号和种类标记、每种强连通分量的顶点数
stack<int> s;                            //求强连通分量辅助栈
bool vis[maxn];                          //顶点访问标记
int max_num;                             //最大顶点数强连通分量顶点数

void add_edge(int u, int v)
{
    edge[++total].v = v;
    edge[total].nxt = head[u];
    head[u] = total;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++times;
    s.push(x);
    vis[x] = true; //进栈标记
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        if (!dfn[edge[i].v]) //未访问该顶点，递归访问设置时间戳
        {
            tarjan(edge[i].v);
            low[x] = min(low[x], low[edge[i].v]); //回溯
        }
        else if (vis[edge[i].v])
            low[x] = min(low[x], low[edge[i].v]);
    }
    if (low[x] == dfn[x])
    {
        cnt++;
        while (x != s.top())
        {
            color[s.top()] = cnt; //将该点染色为cnt号强连通图
            count_color[cnt]++;   //统计当前强连通图点权和
            vis[s.top()] = false; //进栈标记清空
            s.pop();
        }
        color[s.top()] = cnt; //将该点染色为cnt号强连通图
        count_color[cnt]++;   //统计当前强连通图点权和
        vis[s.top()] = false; //进栈标记清空
        s.pop();
        if (count_color[cnt] > count_color[max_num])
            max_num = cnt;
    }
}

int main()
{
    int u, v, op;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> op;
        add_edge(u, v);
        if (op == 2)
            add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    cout << count_color[max_num] << endl;
    for (int i = 1; i <= n; i++)
    {
        if (count_color[color[i]] == count_color[max_num])
        {
            cout << i;
            for (int j = i + 1; j <= n; j++)
                if (color[j] == color[i])
                    cout << " " << j;
            cout << endl;
            return 0;
        }
    }

    return 0;
}