/*
 * POJ 2337
 * 给出n个小写字母组成的单词，要求将n个单词连接起来。使得前一个单词的最后一个字母和
 * 后一个单词的第一个字母相同。输出字典序最小解
 */
#include <bits/stdc++.h>
struct Edge
{
    int to;
    int next;
    int index;
    bool flag;
} edge[2010];

int head[30];
int tot;

void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int index)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = index;
    edge[tot].flag = false;
    head[u] = tot++;
    return;
}

std::string str[1010];
int in[30];
int out[30];
int cnt;
int ans[1010];

void dfs(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        if (!edge[i].flag)
        {
            edge[i].flag = true;
            dfs(edge[i].to);
            ans[cnt++] = edge[i].index;
        }
    }
    return;
}

int main(int argc, const char *argv[])
{
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    int T, n;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
        {
            std::cin >> str[i];
        }
        std::sort(str, str + n); //要输出字典序最小的解，先按照字典序排序
        init();
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        int start = 100;
        for (int i = n - 1; i >= 0; i--) //字典序大的先加入
        {
            int u = str[i][0] - 'a';
            int v = str[i][str[i].length() - 1] - 'a';
            addEdge(u, v, i);
            out[u]++;
            in[v]++;
            if (n < start)
            {
                start = u;
            }
            if (v < start)
            {
                start = v;
            }
        }
        int ccOne = 0;
        int ccTwo = 0;
        for (int i = 0; i < 26; i++)
        {
            if (out[i] - in[i] == 1)
            {
                ccOne++;
                start = 1; //如果有一个出度比入度大1的点，就从这个点出发，否则从最小的点出发
            }
            else if (out[i] - in[i] == -1)
            {
                ccTwo++;
            }
            else if (out[i] - in[i] != 0)
            {
                ccOne = 3;
            }
        }
        if (!((ccOne == 0 && ccTwo == 0) || (ccOne == 1 && ccTwo == 1)))
        {
            std::cout << "***" << '\n';
            continue;
        }
        cnt = 0;
        dfs(start);
        if (cnt != n) //判断是否连通
        {
            std::cout << "***" << '\n';
            continue;
        }
        for (int i = cnt - 1; i >= 0; i--)
        {
            std::cout << str[ans[i]];
            if (i > 0)
            {
                std::cout << '.';
            }
            else
            {
                std::cout << '\n';
            }
        }
    }

    return 0;
}