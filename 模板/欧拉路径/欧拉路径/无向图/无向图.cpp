/*
 * O(E)
 * INIT:adj[][]置为图的邻接表；cnt[a]为a点的邻接点数
 * CALL:alpath(0);  注意：不要有自向边
 */
#include <bits/stdc++.h>
const int V = 10000;
int adj[V][V];
int idx[V][V];
int cnt[V];
int stk[V];
int top = 0;

int path(int v)
{
    for (int w; cnt[v] > 0; v = w)
    {
        stk[top++] = v;
        w = adj[v][--cnt[v]];
        adj[w][idx[w][v]] = adj[w][--cnt[w]];
        //处理的是无向图——边是双向边，删除v->w后，还要处理删除w->v
    }
    return v;
}

void elpath(int b, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < cnt[i]; j++)
        {
            idx[i][adj[i][j]] = j;
        }
    }
    std::cout << b;
    for (top = 0; path(b) == b && top != 0;)
    {
        b = stk[--top];
        std::cout << '-' << b;
    }
    std::cout << std::endl;
}