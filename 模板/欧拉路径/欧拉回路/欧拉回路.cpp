/*
 * SGU 101 无向图
 * 有向图则将无向图中对于度数的判断奇偶改为判断入度和出度是否相等
 */
#include <bits/stdc++.h>

struct Edge
{
    int to;
    int next;
    int index;
    int dir;
    bool flag;
} edge[220];

int head[10]; //前驱
int tot;

void init()
{
    memset(head, -1, sizeof((head)));
    tot = 0;
}

void addEdge(int u, int v, int index)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = index;
    edge[tot].dir = 0;
    edge[tot].flag = false;
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].next = head[v];
    edge[tot].index = index;
    edge[tot].dir = 1;
    edge[tot].flag = false;
    head[v] = tot++;
    return;
}

int du[10];
std::vector<int> ans;

void dfs(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        if (!edge[i].flag)
        {
            edge[i].flag = true;
            edge[i ^ 1].flag = true;
            dfs(edge[i].to);
            ans.push_back(i); //容器尾部插入i
        }
    }
    return;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while (std::cin >> n)
    {
        init();
        int u, v;
        memset(du, 0, sizeof(du));

        for (int i = 1; i <= n; i++)
        {
            std::cin >> u >> v;
            addEdge(u, v, i);
            du[u]++;
            du[v]++;
        }
        int s = -1;
        int cnt = 0;
        //无向图判断奇偶
        for (int i = 0; i <= 6; i++)
        {
            if (du[i] & 1)
            {
                cnt++;
                s = i;
            }
            if (du[i] > 0 && s == -1)
            {
                s = i;
            }
        }
        // 有向图判断出入度是否相同

        if (cnt != 0 && cnt != 2)
        {
            std::cout << "No solution" << '\n';
            continue;
        }
        ans.clear();
        dfs(s);
        if (ans.size() != n)
        {
            std::cout << "No solution" << '\n';
            continue;
        }

        for (int i = 0; i < ans.size(); i++)
        {
            printf("%d ", edge[ans[i]].index);
            if (edge[ans[i]].dir == 0)
            {
                std::cout << "-" << '\n';
            }
            else
            {
                std::cout << "+" << '\n';
            }
        }
    }
    return 0;
}
