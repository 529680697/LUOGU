#include <iostream>
#include <string>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    string s;
    int step;
    node(string _s, int _step) : s(_s), step(_step) {}
};

string s1, s2;
set<pair<string, string>> mp;
set<string> vis;
int ans = 20;

// void dfs(string s, int step)
// {
//     if (step > 10)
//         return;
//     if (s == s2)
//         ans = min(ans, step);
//     string ts;
//     int pos;
//     for (set<pair<string, string>>::iterator it = mp.begin(); it != mp.end(); it++)
//     {
//         ts = s;
//         if ((pos = ts.find(it->first)) != string::npos)
//         {
//             ts.replace(pos, it->first.length(), it->second);
//             // cout << pos << " " << ts << endl;
//             dfs(ts, step + 1);
//         }
//     }
// }

int bfs()
{
    queue<node> q;
    q.push(node(s1, 0));
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        if (now.step > 10)
            return -1;
        if (now.s == s2)
            return now.step;
        string ts;
        int pos;
        for (set<pair<string, string>>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            pos = 0;
            while ((pos = now.s.find(it->first, pos)) != string::npos)
            {
                ts = now.s;
                ts.replace(pos++, it->first.length(), it->second);
                // cout << pos << " " << ts << endl;
                if (!vis.count(ts))
                {
                    q.push(node(ts, now.step + 1));
                    vis.insert(ts);
                }
            }
        }
    }
    return -1;
}

int main()
{
    string a, b;
    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    cin >> s1 >> s2;
    while (cin >> a >> b)
        mp.insert(make_pair(a, b));
    // dfs(s1, 0);
    if ((ans = bfs()) != -1)
        cout << ans << endl;
    else
        cout << "NO ANSWER!" << endl;
    return 0;
}