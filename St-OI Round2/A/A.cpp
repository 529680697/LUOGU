#include <iostream>
#include <stack>

using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;

int n;
int a[maxn];
char b[maxn];
ll dp[maxn];

inline ll count(int x, int y)
{
    stack<ll> num;
    ll tmpa;
    num.push(a[x]);
    for (int i = x + 1; i <= y; i++)
    {
        if (b[i] == '*')
        {
            tmpa = num.top();
            num.pop();
            tmpa *= a[i];
            num.push(tmpa);
        }
        else
        {
            num.push(a[i]);
        }
    }
    tmpa = num.top(), num.pop();
    while (!num.empty())
    {
        tmpa += num.top();
        num.pop();
    }
    return tmpa;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> b[i] >> a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            // {
            //     cout << count(i, j) << endl;
            // }
            ans = (ans + count(i, j)) % 998244353;
    cout << ans << endl;
    return 0;
}