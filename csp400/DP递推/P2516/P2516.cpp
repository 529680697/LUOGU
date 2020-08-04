#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MOD 100000000

using namespace std;
const int maxn = 5005;

char s1[maxn], s2[maxn];
int f[2][maxn], r[2][maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%s%s", s1 + 1, s2 + 1);
    int l1 = strlen(s1 + 1) - 1, l2 = strlen(s2 + 1) - 1;
    int now = 1, pre = 0;
    for (int i = 0; i <= l2; i++)
        r[0][i] = 1;
    for (int i = 1; i <= l1; i++)
    {
        r[now][0] = 1;
        for (int j = 1; j <= l2; j++)
        {
            f[now][j] = max(f[pre][j], f[now][j - 1]);
            r[now][j] = 0;

            // if (s1[i] == s2[j])
            // {
            //     f[now][j] = max(f[now][j], f[pre][j - 1] + 1);
            //     r[now][j] += r[pre][j - 1];
            //     if (f[pre][j] == f[now][j])
            //         r[now][j] += r[pre][j];
            //     if (f[now][j - 1] == f[now][j])
            //         r[now][j] += r[now][j - 1];
            // }
            // else
            // {
            //     if (f[pre][j] == f[now][j])
            //         r[now][j] += r[pre][j];
            //     if (f[now][j - 1] == f[now][j])
            //         r[now][j] += r[now][j - 1];
            //     if (f[pre][j - 1] == f[now][j])
            //         r[now][j] -= r[pre][j - 1];
            // }

            if (s1[i] == s2[j])
                f[now][j] = max(f[now][j], f[pre][j - 1] + 1);
            if (f[pre][j] == f[now][j])
                r[now][j] += r[pre][j];
            if (f[now][j - 1] == f[now][j])
                r[now][j] += r[now][j - 1];
            if (s1[i] == s2[j] && f[now][j] == f[pre][j - 1] + 1)
                r[now][j] += r[pre][j - 1];
            if (s1[i] != s2[j] && f[pre][j - 1] == f[now][j])
                r[now][j] -= r[pre][j - 1];
            r[now][j] = (r[now][j] + MOD) % MOD;
        }
        now = pre, pre = 1 - pre;
    }
    cout << f[pre][l2] << endl
         << r[pre][l2] << endl;
    return 0;
}