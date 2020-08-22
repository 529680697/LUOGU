#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 10005;

int n;
int a[maxn], ans[maxn], sum;
vector<int> v[maxn];

int count(int x)
{
    if (ans[x])
        return ans[x];
    ans[x] = a[x];
    int tmp = 0;
    for (int i = 0; i < v[x].size(); i++)
    {
        tmp = max(tmp, count(v[x][i]));
    }
    ans[x] += tmp;
    return ans[x];
}

int main()
{
    int m, c;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> a[i];
        while (cin >> c && c)
            v[i].push_back(c);
    }
    for (int i = 1; i <= n; i++)
    {
        sum = max(sum, count(i));
        // cout << sum << endl;
    }
    cout << sum << endl;
    return 0;
}