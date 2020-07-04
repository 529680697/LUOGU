#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int weight;
    int left_top, right_bottom, right_top, left_bottom;
} node[1005][1005];
int n, m;

void rb2lt() //右下角到左上dp
{
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            node[i][j].right_bottom = node[i][j].weight + max(node[i][j + 1].right_bottom, node[i + 1][j].right_bottom);
}

void lb2rt() //左下角到右上dp
{
    for (int i = n; i > 0; i--)
        for (int j = 1; j <= m; j++)
            node[i][j].left_bottom = node[i][j].weight + max(node[i + 1][j].left_bottom, node[i][j - 1].left_bottom);
}

void lt2rb() //左上角到右下dp
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            node[i][j].left_top = node[i][j].weight + max(node[i - 1][j].left_top, node[i][j - 1].left_top);
}

void rt2lb() //右上角到左下dp
{
    for (int i = 1; i <= n; i++)
        for (int j = m; j > 0; j--)
            node[i][j].right_top = node[i][j].weight + max(node[i][j + 1].right_top, node[i - 1][j].right_top);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &(node[i][j].weight));
    rb2lt();
    lb2rt();
    lt2rb();
    rt2lb();
    int x = 0;
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            x = max(x, node[i][j - 1].left_top + node[i][j + 1].right_bottom + node[i + 1][j].left_bottom + node[i - 1][j].right_top);
            x = max(x, node[i - 1][j].left_top + node[i + 1][j].right_bottom + node[i][j - 1].left_bottom + node[i][j + 1].right_top);
        }
    }
    cout << x << endl;
    return 0;
}