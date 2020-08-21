#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1e5 + 5;

struct node
{
    int t;
    vector<int> v;
} ship[maxn];

int n, guoji[300005], tot = 0;
queue<int> q;

int main()
{
    int j, k;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ship[i].t >> k;
        while (k--)
        {
            cin >> j;
            ship[i].v.push_back(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        q.push(i);
        for (int l = 0; l < ship[i].v.size(); l++)
        {
            guoji[ship[i].v[l]]++;
            if (guoji[ship[i].v[l]] == 1)
                tot++;
        }
        while (ship[i].t - ship[q.front()].t >= 86400)
        {
            for (int l = 0; l < ship[q.front()].v.size(); l++)
            {
                guoji[ship[q.front()].v[l]]--;
                if (guoji[ship[q.front()].v[l]] == 0)
                    tot--;
            }
            q.pop();
        }
        cout << tot << endl;
    }

    return 0;
}