#include <iostream>
#include <cstdio>
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
        return a.v < v;
    }
};

inline int get_num()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x;
}

int n, k, a;
priority_queue<node> q;

int main()
{
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin >> n >> k;
    // cout << 0 << endl;
    // cin >> a;
    n = get_num(), k = get_num();
    puts("0");
    a = get_num();
    q.push(node(a, 0));
    for (int i = 1; i < n; i++)
    {
        a = get_num();
        // cout << q.top().v << endl;
        printf("%d\n", q.top().v);
        while (!q.empty() && q.top().i <= i - k)
            q.pop();
        q.push(node(a, i));
    }
    return 0;
}