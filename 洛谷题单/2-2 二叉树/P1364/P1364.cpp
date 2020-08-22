#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int w, l, r;
    int fa, dep;
} no[105];

int n;
bool not_root[105];

int count_dis(int a, int b, int d)
{
    if (a == b)
        return d;
    if (no[a].dep == no[b].dep)
        return count_dis(no[a].fa, no[b].fa, d + 2);
    else if (no[a].dep > no[b].dep)
        return count_dis(no[a].fa, b, d + 1);
    else
        return count_dis(no[b].fa, a, d + 1);
}

void update_dep(int i, int dep)
{
    no[i].dep = dep;
    if (no[i].l)
        update_dep(no[i].l, dep + 1);
    if (no[i].r)
        update_dep(no[i].r, dep + 1);
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> no[i].w >> no[i].l >> no[i].r;
        not_root[no[i].l] = not_root[no[i].r] = true;
        no[no[i].l].fa = no[no[i].r].fa = i;
    }
    for (int i = 1; i <= n; i++)
        if (!not_root[i])
        {
            update_dep(i, 1);
            break;
        }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            tmp += no[j].w * count_dis(i, j, 0);
            //            cout << count_dis(i, j, 0) << endl;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
