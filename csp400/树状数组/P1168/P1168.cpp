#include <iostream>
#include <algorithm>
#include <map>

#define lowbit(i) ((i) & (-i))

using namespace std;
const int maxn = 100005;

struct node
{
    int v, pos;
} tmp[maxn];
int n, a[maxn], c[maxn];
map<int, int> mp;

void update(int x, int v)
{
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}

int getsum(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

int findKelement(int k)
{
    int l = 1, r = maxn, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (getsum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

bool cmp(node a, node b)
{
    return a.v < b.v;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i].v;
        tmp[i].pos = i;
    }
    sort(tmp, tmp + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || tmp[i].v != tmp[i - 1].v)
        {
            mp[i + 1] = tmp[i].v;
            a[tmp[i].pos] = i + 1;
        }
        else
        {
            a[tmp[i].pos] = a[tmp[i - 1].pos];
        }
    }
    for (int i = 0; i < n; i++)
    {
        update(a[i], 1);
        if ((i & 1) == 0)
        {
            cout << mp[findKelement((i + 3) >> 1)] << endl;
        }
    }

    return 0;
}