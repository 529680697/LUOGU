#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5e5 + 5;

struct node
{
    int l, r;
    char c;
} no[maxn];

int head[maxn], total, dpmin[maxn][3], dpmax[maxn][3];
string s;

void init()
{
    int now = ++total;
    no[now].c = s[total - 1];
    switch (s[total - 1])
    {
    case '1':
        no[now].l = now + 1;
        init();
        break;
    case '2':
        no[now].l = now + 1;
        init();
        no[now].r = total + 1;
        init();
        break;
    }
}

void print(int x)
{
    cout << no[x].c << endl;
    if (no[x].l)
        print(no[x].l);
    if (no[x].r)
        print(no[x].r);
}

void dfs(int x)
{
    if (dpmin[x][0])
        return;
    switch (no[x].c)
    {
    case '0':
        dpmin[x][0] = dpmin[x][2] = 0;
        dpmin[x][1] = 1;
        dpmax[x][0] = dpmax[x][1] = 1;
        dpmax[x][2] = 0;
        break;
    case '1':
        dfs(no[x].l);
        dpmin[x][1] = 1 + dpmin[no[x].l][2];
        dpmin[x][2] = dpmin[no[x].l][0];
        dpmin[x][0] = min(dpmin[x][1], dpmin[x][2]);
        dpmax[x][1] = 1 + dpmax[no[x].l][2];
        dpmax[x][2] = dpmax[no[x].l][0];
        dpmax[x][0] = max(dpmax[x][1], dpmax[x][2]);
        break;
    case '2':
        dfs(no[x].l);
        dfs(no[x].r);
        dpmin[x][1] = 1 + dpmin[no[x].l][2] + dpmin[no[x].r][2];
        dpmin[x][2] = min(dpmin[no[x].l][2] + dpmin[no[x].r][1], dpmin[no[x].l][1] + dpmin[no[x].r][2]);
        dpmin[x][0] = min(dpmin[x][1], dpmin[x][2]);
        dpmax[x][1] = 1 + dpmax[no[x].l][2] + dpmax[no[x].r][2];
        dpmax[x][2] = max(dpmax[no[x].l][2] + dpmax[no[x].r][1], dpmax[no[x].l][1] + dpmax[no[x].r][2]);
        dpmax[x][0] = max(dpmax[x][1], dpmax[x][2]);
        break;
    default:
        break;
    }
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> s;
    init();
    // print(1);
    dfs(1);
    cout << dpmax[1][0] << " " << dpmin[1][0] << endl;
    return 0;
}
