#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 6e4 + 5;
const int M = (1 << 26) + 5;

int n, m, a[N], bl, pos[N], ans, anss[N];
unsigned short c[M];
char s[N]; //保存人员编号
struct qujian
{
    int l, r, id;
    bool operator<(const qujian &a) const
    {
        return pos[l] == pos[a.l] ? r < a.r : pos[l] < pos[a.l];
    }
} q[N]; //保存查询区间

inline void add(int x)
{
    ans += c[a[x]]++;
    for (int i = 0; i < 26; i++)
    {
        ans += c[a[x] ^ (1 << i)];
    }
}

inline void del(int x)
{
    ans -= --c[a[x]];
    for (int i = 0; i < 26; i++)
    {
        ans -= c[a[x] ^ (1 << i)];
    }
}

void solve()
{
    sort(q + 1, q + 1 + m);
    c[0]++;
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (r < q[i].r)
            add(++r);
        while (r > q[i].r)
            del(r--);
        while (l < q[i].l)
            del(l - 1), l++;
        while (l > q[i].l)
            --l, add(l - 1);
        anss[q[i].id] = ans;
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", anss[i]);
    }
}

int main()
{
    cin >> n >> m;
    scanf("%s", s + 1);
    bl = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (1 << (s[i] - 'a')) ^ a[i - 1];
        pos[i] = (i - 1) / bl + 1;
    }
    for (int i = 1; i <= m; i++)
    {
        q[i].id = i;
        scanf("%d%d", &q[i].l, &q[i].r);
    }
    solve();
    return 0;
}