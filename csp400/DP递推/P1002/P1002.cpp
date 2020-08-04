#include <iostream>

using namespace std;
const int maxn = 40;

int n, m, a, b;
unsigned long long f[maxn][maxn];
bool vis[maxn][maxn];

void init()
{
    fill(vis[0], vis[0] + maxn * maxn, true);
    a += 10, b += 10;
    vis[a][b] = false;
    vis[a - 2][b - 1] = vis[a - 1][b - 2] = vis[a - 2][b + 1] = vis[a - 1][b + 2] = false;
    vis[a + 1][b - 2] = vis[a + 2][b - 1] = vis[a + 1][b + 2] = vis[a + 2][b + 1] = false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> a >> b;
    init();
    f[10 + n][10 + m] = 1;
    for (int i = 9 + n; i >= 10; i--)
        if (vis[i][10 + m])
            f[i][10 + m] = f[i][11 + m] + f[i + 1][10 + m];
    for (int i = 10 + n; i >= 10; i--)
        for (int j = 9 + m; j >= 10; j--)
            if (vis[i][j])
                f[i][j] = f[i + 1][j] + f[i][j + 1];
    cout << f[10][10] << endl;
    return 0;
}