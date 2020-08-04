#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxm = 65;
const int maxn = 32005;
struct node
{
    int w, c;
    node(int _w, int _c) : w(_w), c(_c) {}
};

int n, m, dp[maxn];
vector<node> v[maxm];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int a, b, d;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> d;
        if (d)
            v[d].push_back(node(a, a * b));
        else
            v[i].push_back(node(a, a * b));
    }
    for (int i = 1; i <= m; i++)
        switch (v[i].size())
        {
        case 2:
            v[i].push_back(node(v[i][0].w + v[i][1].w, v[i][0].c + v[i][1].c));
            v[i].erase(v[i].begin() + 1);
            break;
        case 3:
            v[i].push_back(node(v[i][0].w + v[i][1].w, v[i][0].c + v[i][1].c));
            v[i].push_back(node(v[i][0].w + v[i][2].w, v[i][0].c + v[i][2].c));
            v[i].push_back(node(v[i][0].w + v[i][1].w + v[i][2].w, v[i][0].c + v[i][1].c + v[i][2].c));
            v[i].erase(v[i].begin() + 1, v[i].begin() + 3);
            break;
        default:
            break;
        }
    for (int i = 1; i <= m; i++)
        if (v[i].size())
            for (int j = n; j > 0; j--)
                for (int l = 0; l < v[i].size(); l++)
                    if (j >= v[i][l].w)
                        dp[j] = max(dp[j], dp[j - v[i][l].w] + v[i][l].c);
    cout << dp[n] << endl;
    return 0;
}