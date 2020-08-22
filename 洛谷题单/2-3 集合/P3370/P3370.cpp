#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int p = 1e7 + 19;

int n;
vector<int> ans;

ll hashFunc(string s)
{
    ll h = 0;
    for (int i = 0; i < s.length(); i++)
    {
        h = (h * p + s[i]) % mod;
    }
    return h;
}

int main()
{
    string s;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ans.push_back(hashFunc(s));
    }
    sort(ans.begin(), ans.end());
    int count = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0 || ans[i] != ans[i - 1])
            count++;
    }
    cout << count << endl;
    return 0;
}