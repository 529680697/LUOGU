#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e6 + 5;

struct node
{
    int v, i;
    node(int _v, int _i) : v(_v), i(_i) {}
    bool operator<(const node &a) const
    {
        return v < a.v;
    }
};

int n, k, a;
priority_queue<node> q;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a;
        q.push(node(a, i));
    }
    cout << q.top().v << endl;
    for (int i = k; i < n; i++)
    {
        cin >> a;
        while (q.top().i <= i - k)
            q.pop();
        q.push(node(a, i));
        cout << q.top().v << endl;
    }

    return 0;
}