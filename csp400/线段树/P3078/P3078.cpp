#include <iostream>

using namespace std;
const int maxn = 1e5 + 5;

int n, a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            ans += a[i] - a[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}