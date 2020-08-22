#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    string s1, s2;
    int ans = 0;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        for (int j = 1; j < s2.length(); j++)
        {
            if (s1[i] == s2[j] && s1[i + 1] == s2[j - 1])
                ans++;
        }
    }
    cout << (1 << ans) << endl;
    return 0;
}