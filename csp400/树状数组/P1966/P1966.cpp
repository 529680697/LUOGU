#include <iostream>
#include <algorithm>

#define MOD 99999997
#define lowbit(i) ((i) & (-i))

using namespace std;
const int maxn = 1e5 + 5;

struct node
{
    int val, pos;
} tmp_a[maxn], tmp_b[maxn]; //原火柴高度

int n;
int a[maxn], b[maxn];  //离散化到1-n后的火柴高度
int mp[maxn], c[maxn]; //顺序化a1后的火柴高度，mp为a1映射到1-n
int C[maxn];

bool cmp(node a, node b)
{
    return a.val < b.val;
}

void update(int x, int v)
{
    for (int i = x; i < maxn; i += lowbit(i))
    {
        C[i] += v;
    }
}

int get_sum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += C[i];
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp_a[i].val;
        tmp_a[i].pos = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp_b[i].val;
        tmp_b[i].pos = i;
    }
    //离散化到1-n
    sort(tmp_a, tmp_a + n, cmp);
    sort(tmp_b, tmp_b + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || tmp_a[i].val != tmp_a[i - 1].val)
            a[tmp_a[i].pos] = i + 1;
        else
            a[tmp_a[i].pos] = a[tmp_a[i - 1].pos];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || tmp_b[i].val != tmp_b[i - 1].val)
            b[tmp_b[i].pos] = i + 1;
        else
            b[tmp_b[i].pos] = b[tmp_b[i - 1].pos];
    }
    //顺序化a到1-n
    for (int i = 0; i < n; i++)
        mp[a[i]] = i + 1;
    for (int i = 0; i < n; i++)
        c[i + 1] = mp[b[i]];
    //求逆序对数
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        update(c[i], 1);
        ans = (ans + get_sum(n) - get_sum(c[i])) % MOD;
    }
    cout << ans << endl;
    return 0;
}