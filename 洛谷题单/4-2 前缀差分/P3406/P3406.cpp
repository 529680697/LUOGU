#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 100005;

struct node
{
    unsigned long long a, b, c;
    unsigned long long count_ans(int x)
    {
        return min(a * x, c + b * x);
    }
} no[maxn];

int n, m, g[maxn], num[maxn];

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> a;
    for (int i = 1; i < m; i++)
    {
        cin >> b;
        if (a > b)
            g[b]++, g[a]--;
        else
            g[a]++, g[b]--;
        a = b;
    }
    for (int i = 1; i < n; i++)
    {
        num[i] = num[i - 1] + g[i];
        // cout << num[i] << endl;
    }
    unsigned long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> no[i].a >> no[i].b >> no[i].c;
        ans += no[i].count_ans(num[i]);
    }
    cout << ans << endl;
    return 0;
}