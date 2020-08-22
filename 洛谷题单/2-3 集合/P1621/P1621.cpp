#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
const int maxn = 1e5 + 5;

int a, b, p;
int prime[maxn], pnum, fa[maxn], is_fa[maxn];
int v[10000];

inline bool is_prime(int n)
{
    if (n == 1)
        return false;
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++)
        if (n % i == 0)
            return false;
    return true;
}

inline void find_prime()
{
    for (int i = p; i <= b; i++)
        if (is_prime(i))
            prime[pnum++] = i;
}

inline int find_fa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find_fa(fa[x]);
}

inline void Union(int x, int y)
{
    x = find_fa(x);
    y = find_fa(y);
    if (x != y)
        fa[x] = y;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> a >> b >> p;
    find_prime();
    for (int i = a; i <= b; i++) //并查集初始化
        fa[i] = i;
    //     cout << pnum << endl;
    for (int i = 0; i < pnum; i++)
    {
        int num = 0;
        while (num < a)
            num += prime[i];
        while (num + prime[i] <= b)
        {
            Union(num, num + prime[i]);
            num += prime[i];
        }
    }

    for (int i = a; i <= b; i++)
        is_fa[find_fa(i)] = 1;
    int ans = 0;
    for (int i = a; i <= b; i++)
        if (is_fa[i])
            ans++;
    cout << ans << endl;
    return 0;
}
