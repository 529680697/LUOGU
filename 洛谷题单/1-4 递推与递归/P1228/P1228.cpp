#include <iostream>

#define lu dfs(a + l - 1, b + l - 1, a, b, l); //左上角
#define ld dfs(a + l, b + l - 1, a + l, b, l); //左下角
#define ru dfs(a + l - 1, b + l, a, b + l, l); //右上角
#define rd dfs(a + l, b + l, a + l, b + l, l); //右下角

using namespace std;
const int maxn = (1 << 10) + 5;

int k, x, y;

void dfs(int x, int y, int a, int b, int l)
{
    if (l == 1)
        return;
    l >>= 1;
    if (x - a < l && y - b < l) //左上角
    {
        cout << a + l << " " << b + l << " " << 1 << endl;
        dfs(x, y, a, b, l);
        ru
            ld
                rd
    }
    else if (x - a < l && y - b >= l) //右上角
    {
        cout << a + l << " " << b + l - 1 << " " << 2 << endl;
        lu
            dfs(x, y, a, b + l, l);
        ld
            rd
    }
    else if (x - a >= l && y - b < l) //左下角
    {
        cout << a + l - 1 << " " << b + l << " " << 3 << endl;
        lu
            ru
                dfs(x, y, a + l, b, l);
        rd
    }
    else if (x - a >= l && y - b >= l) //右下角
    {
        cout << a + l - 1 << " " << b + l - 1 << " " << 4 << endl;
        lu
            ru
                ld
                    dfs(x, y, a + l, b + l, l);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> k >> x >> y;
    dfs(x, y, 1, 1, 1 << k);
    return 0;
}