#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;

int t, n;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (n + 1) / 2 << endl;
    }
    return 0;
}