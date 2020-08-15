#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int n, num[5005];
ll ans = 0, c[500005];

inline ll get_c(int x)
{
    if (c[x] != 0)
        return c[x];
    c[x] = ((ll)x * (x - 1)) >> 1;
    return c[x];
}

int main()
{
    int a;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        num[a]++;
    }
    for (int i = 2; i < 5001; i++)
    {
        if (num[i] >= 2)
        {
            ll C = get_c(num[i]);
            for (int j = 1; j < ((i + 1) >> 1); j++)
                if (num[j] > 0 && num[i - j] > 0)
                    ans = (ans + C * num[j] * num[i - j]) % mod;
            if (!(i & 1) && (num[i >> 1]) > 1)
                ans = (ans + C * get_c(num[i >> 1])) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}