#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

int n, k;
ll a[maxn];
deque<int> q1, q2;

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        while (!q1.empty() && a[q1.back()] > a[i])
            q1.pop_back();
        if (!q1.empty() && i - q1.front() >= k)
            q1.pop_front();
        q1.push_back(i);
        if (i >= k - 1)
            cout << a[q1.front()] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        while (!q2.empty() && a[q2.back()] < a[i])
            q2.pop_back();
        if (!q2.empty() && i - q2.front() >= k)
            q2.pop_front();
        q2.push_back(i);
        if (i >= k - 1)
            cout << a[q2.front()] << " ";
    }
    cout << endl;
    return 0;
}