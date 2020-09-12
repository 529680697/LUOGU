// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int n, k, ans;
vector<int> a;

// bool cmp(int a, int b)
// {
//     return a < b;
// }

int main()
{
    int tmp;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    // a.push_back(inf);
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;
    int max_len = 0, max_begin = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp_len = upper_bound(a.begin() + i, a.end(), a[i] + k) - a.begin() - i;
        if (tmp_len >= max_len)
        {
            max_len = tmp_len;
            max_begin = i;
        }
    }
    ans = max_len;
    // cout << max_begin << " " << max_len << endl;
    a.erase(a.begin() + max_begin, a.begin() + max_begin + max_len);
    // for (int i = 0; i < a.size(); i++)
    //     cout << a[i] << " ";
    // cout << endl;
    max_len = 0, max_begin = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int tmp_len = upper_bound(a.begin() + i, a.end(), a[i] + k) - a.begin() - i;
        if (tmp_len >= max_len)
        {
            max_len = tmp_len;
            max_begin = i;
        }
    }
    // cout << max_begin << " " << max_len << endl;
    cout << max_len + ans << endl;
    return 0;
}