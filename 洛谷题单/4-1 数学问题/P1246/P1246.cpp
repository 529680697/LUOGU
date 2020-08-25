#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

string s;

int c(int n, int m)
{
    int ans = 1;
    for (int i = 1; i <= m; i++)
        ans = ans * (n - m + i) / i;
    return ans;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i - 1] >= s[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i < s.length(); i++)
        ans += c(26, i);
    for (int i = 0; i < s.length(); i++)
    {
        for (char j = (i == 0 ? 'a' : s[i - 1] + 1); j < s[i]; j++)
        {
            ans += c('z' - j, s.length() - i - 1);
        }
    }
    cout << ++ans << endl;
    return 0;
}