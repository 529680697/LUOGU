#include <iostream>

using namespace std;
const int maxn = 2e3 + 5;

struct node
{
    int lx, ly, rx, ry;
} a[maxn];

long long num, ans, n, m;

int main()
{
    int x, y;
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].lx >> a[i].ly >> a[i].rx >> a[i].ry;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        num = 0;
        for (int j = 1; j <= n; j++)
            if (x >= a[j].lx && x <= a[j].rx && y >= a[j].ly && y <= a[j].ry)
                num++, ans = j;
        if (num == 0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES " << num << " " << ans << endl;
    }

    return 0;
}