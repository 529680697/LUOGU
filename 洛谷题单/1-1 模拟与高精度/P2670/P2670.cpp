#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
bool a[110][110];
int num[110][110];
int x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

inline int add(int i, int j)
{
    int ans = 0;
    for (int k = 0; k < 8; k++)
        ans += a[i + x[k]][j + y[k]];
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '*')
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!a[i][j])
                num[i][j] = add(i, j);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j])
                printf("*");
            else
                printf("%d", num[i][j]);
        }
        printf("\n");
    }

    return 0;
}