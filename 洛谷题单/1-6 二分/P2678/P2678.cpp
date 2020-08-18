#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 50005;

// struct node
// {
//     bool flag;
//     int l, r;
//     int get_min()
//     {
//         return l < r ? l : r;
//     }
//     int get_max()
//     {
//         return l < r ? r : l;
//     }
//     bool operator<(node &x)
//     {
//         if (get_min() < x.get_min())
//             return true;
//         else if (get_min() == x.get_min())
//             return get_max() < x.get_max();
//         else
//             return false;
//     }
// } no[maxn];

int d, n, m, a[maxn];

// inline int find_min()
// {
//     int j = 0;
//     while (no[j].flag)
//     {
//         j++;
//     }
//     for (int i = j + 1; i < n; i++)
//     {
//         if (!no[i].flag && no[i] < no[j])
//         {
//             j = i;
//         }
//     }
//     return j;
// }

bool judge(int mid)
{
    int tot = 0;
    int now = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i] - a[now] < mid)
            tot++;
        else
            now = i;
    }
    if (tot > m)
        return false;
    else
        return true;
}

int main()
{
    // int pre, a;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    // cin >> l >> n >> m >> a;
    // no[0].l = a, pre = a;
    // for (int i = 1; i < n; i++)
    // {
    //     cin >> a;
    //     no[i].l = a - pre;
    //     no[i - 1].r = no[i].l;
    //     pre = a;
    // }
    // no[n - 1].r = l - a;
    // for (int i = 0; i < m; i++)
    // {
    //     int MIN = find_min();
    //     // cout << MIN << endl;
    //     no[MIN].flag = true;
    //     for (int j = MIN + 1; j < n; j++)
    //     {
    //         if (!no[j].flag)
    //         {
    //             no[j].l += no[MIN].l;
    //             // cout << no[j].l << endl;
    //             break;
    //         }
    //     }
    //     for (int j = MIN - 1; j >= 0; j--)
    //     {
    //         if (!no[j].flag)
    //         {
    //             no[j].r += no[MIN].r;
    //             // cout << no[j].r << endl;
    //             break;
    //         }
    //     }
    // }
    // int MIN = no[find_min()].get_min();
    // cout << MIN << endl;
    // return 0;

    cin >> d >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = d;
    int l = 1, r = d, mid, ans;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}