#include <iostream>
#include <algorithm>

#define lowbit(i) ((i) & (-i))
using namespace std;
typedef long long ull;
const int maxn = 300005;

struct node
{
    ull val;
    int pos;
} tmp[maxn];

int n, m;
ull a[maxn], c[maxn], num[maxn];
bool vis[maxn], v[maxn];
ull _sum = 0, cnt = 0;

bool cmp(node &a, node &b)
{
    return a.val < b.val;
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        c[i] += v;
    }
}

ull get_sum(int x)
{
    ull sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += c[i];
    }
    return sum;
}

void deal(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && !v[a[i]] && a[i] <= a[k])
        {
            _sum -= num[a[i]];
            v[a[i]] = vis[i] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i].val;
        tmp[i].pos = i;
    }
    //离散化到1--n
    sort(tmp, tmp + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || tmp[i].val != tmp[i - 1].val)
            a[tmp[i].pos] = i + 1;
        else
            a[tmp[i].pos] = a[tmp[i - 1].pos];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        update(a[i], 1);
        num[a[i]] += get_sum(a[i] - 1);
        _sum += get_sum(a[i] - 1);
    }
    cout << _sum << endl;
    int k;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        k--;
        if (!vis[k])
        {
            deal(k);
        }
        cout << _sum << endl;
    }

    return 0;
}