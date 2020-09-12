// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int change[13][5];
struct node
{
    int state[13];
    int step;
    vector<int> path;
    void next(int x)
    {
        int j = change[x][state[x]];
        state[j] = state[j] % 4 + 1;
        state[x] = state[x] % 4 + 1;
        step++;
        path.push_back(x);
    }
    bool check()
    {
        for (int i = 1; i < 13; i++)
            if (state[i] != 1)
                return false;
        return true;
    }
} button;

int n;
queue<node> q;

node bfs()
{
    q.push(button);
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        if (now.check())
            return now;
        for (int i = 1; i < 13; i++)
        {
            node b = now;
            b.next(i);
            q.push(b);
        }
    }
    return button;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 1; i <= 12; i++)
        cin >> button.state[i] >> change[i][1] >> change[i][2] >> change[i][3] >> change[i][4];
    node ans = bfs();
    cout << ans.step << endl;
    for (int i = 0; i < ans.path.size(); i++)
        cout << ans.path[i] << " ";
    return 0;
}