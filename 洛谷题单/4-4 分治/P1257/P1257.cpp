#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4 + 5;

struct node
{
    double x, y;
    bool operator<(const node &a) const
    {
        if (x == a.x)
            return y < a.y;
        else
            return x < a.x;
    }
} no[maxn];

int n, temp[maxn];

bool cmp(int x, int y)
{
    return no[x].y < no[y].y;
}

inline double get_dis(int x, int y)
{
    return sqrt((no[x].x - no[y].x) * (no[x].x - no[y].x) + (no[x].y - no[y].y) * (no[x].y - no[y].y));
}

double merge(int l, int r)
{
    double dis = inf;
    if (l == r)
        return dis;
    if (l + 1 == r)
        return get_dis(l, r);
    int mid = (l + r) >> 1;
    double d1 = merge(l, mid);
    double d2 = merge(mid + 1, r);
    dis = min(d1, d2);
    int k = 0;
    for (int i = l; i <= r; i++)
        if (fabs(no[i].x - no[mid].x) <= dis)
            temp[k++] = i;
    sort(temp, temp + k, cmp);
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k && no[temp[j]].y - no[temp[i]].y < dis; j++)
            dis = min(dis, get_dis(temp[i], temp[j]));
    return dis;
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> no[i].x >> no[i].y;
    sort(no, no + n);
    cout << fixed << setprecision(4) << merge(0, n - 1) << endl;
    return 0;
}