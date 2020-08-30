#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;

int n, m;
ll l[maxn], r[maxn], h[maxn], ans;
char f[maxn][maxn];

void ddzl()
{
    stack<int> s;
    for (int i = m; i > 0; i--)
    {
        while (!s.empty() && h[i] <= h[s.top()])
            l[s.top()] = i, s.pop();
        s.push(i);
    }
    while (!s.empty())
    {
        l[s.top()] = 0;
        s.pop();
    }
}

void ddzr()
{
    stack<int> s;
    for (int i = 1; i <= m; i++)
    {
        while (!s.empty() && h[i] < h[s.top()])
            r[s.top()] = i, s.pop();
        s.push(i);
    }
    while (!s.empty())
    {
        r[s.top()] = m + 1;
        s.pop();
    }
}

void work()
{
    ddzl(), ddzr();
    for (int i = 1; i <= m; i++)
        ans += (i - l[i]) * (r[i] - i) * h[i];
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> f[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (f[i][j] == '*')
                h[j] = 0;
            else
                h[j]++;
        }
        work();
    }
    cout << ans << endl;
    return 0;
}