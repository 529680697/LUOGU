#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int v, dep;
    node() {}
    node(int _v, int _dep) : v(_v), dep(_dep) {}
};

int n, m, inDegreeNum[30];
int g[30][30];
vector<int> adj[30], indegree[30];
bool flag;
queue<int> ans;

bool to_pol_sort()
{
    queue<node> q;
    while (!ans.empty())
        ans.pop();
    for (int i = 0; i < n; i++)
        if ((inDegreeNum[i] = indegree[i].size()) == 0)
            q.push(node(i, 1));
    int num = 0;
    int cur_dep = 0;
    while (!q.empty())
    {
        node now = q.front();
        ans.push(now.v);
        q.pop();
        cur_dep = now.dep;
        for (int i = 0; i < adj[now.v].size(); i++)
        {
            int v = adj[now.v][i];
            inDegreeNum[v]--;
            if (inDegreeNum[v] == 0)
                q.push(node(v, cur_dep + 1));
        }
        num++;
    }
    if (num == n)
    {
        if (cur_dep == n)
        {
            flag = true;
            return true;
        }
        else
        {
            flag = false;
            return true;
        }
    }
    else
        return false;
}

int main()
{
    char a, b;
    freopen("in", "r", stdin);
    // ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        // scanf("%c<%c", &a, &b);
        cin >> a >> b >> b;
        int x = a - 'A', y = b - 'A';
        if (g[x][y] == 0)
        {
            g[x][y] = 1;
            g[y][x] = -1;
            adj[x].push_back(y);
            indegree[y].push_back(x);
            if (to_pol_sort())
            {
                if (flag)
                {
                    cout << "Sorted sequence determined after " << i << " relations: ";
                    while (!ans.empty())
                    {
                        printf("%c", ans.front() + 'A');
                        ans.pop();
                    }
                    cout << "." << endl;
                    return 0;
                }
            }
            else
            {
                cout << "Inconsistency found after " << i << " relations." << endl;
                return 0;
            }
        }
        else if (g[x][y] == -1)
        {
            cout << "Inconsistency found after " << i << " relations." << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << endl;
    return 0;
}
