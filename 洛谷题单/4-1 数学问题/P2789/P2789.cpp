#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, ans;
bool flag[305];

void f(int x, int y)
{
    if (x == 0)
    {
        if (!flag[y])
            ans++, flag[y] = true;
    }
    else
        for (int i = x; i > 0; i--)
            f(x - i, i * (x - i) + y);
}

int main()
{
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n;
    f(n, 0);
    cout << ans << endl;
    return 0;
}
