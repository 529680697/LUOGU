#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll maxn = 2000005;

ll n, m, a[maxn], sum, ans;

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[0] != 1)
    {
        cout << "No answer!!!" << endl;
        return 0;
    }
    a[n] = m;
    for (int i = 0; i < n; i++)
    {
        while (sum < a[i + 1] - 1)
        {
            sum += a[i];
            ans++;
            if (sum >= m)
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans + 1 << endl;
    return 0;
}