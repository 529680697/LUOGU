#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 2005;

int t, k;
int c[maxn][maxn], s[maxn][maxn];

void init()
{
    c[0][0] = c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 2000; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            if (!c[i][j])
                s[i][j]++;
        }
        s[i][i + 1] = s[i][i];
    }
}

int main()
{
    int a, b;
    freopen("in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> t >> k;
    init();
    while (t--)
    {
        cin >> a >> b;
        if (b > a)
            b = a;
        cout << s[a][b] << endl;
    }
    return 0;
}