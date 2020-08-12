#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 25;

int n, m;
int a[maxn * maxn], no[maxn][maxn], ti[maxn][maxn], gongxu[maxn * maxn], _begin[maxn];
struct node
{
    bool work[8000];
    int end;

    void fill(int gongjian, int len)
    {
        for (int i = _begin[gongjian];;)
        {
            while (work[i])
                i++;
            int t_len = 0, j = i;
            while (t_len < len && !work[j])
                t_len++, j++;
            if (t_len == len)
            {
                while (j > i)
                {
                    work[--j] = true;
                }
                // cout << i << " " << t_len << endl;
                end = max(end, i + t_len - 1);
                _begin[gongjian] = i + t_len;
                return;
            }
            else
                i = j;
        }
    }
} machine[maxn];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> m >> n;
    int num[maxn];
    memset(num, 0, sizeof(num));
    fill(_begin, _begin + maxn, 1);
    for (int i = 0; i < n * m; i++)
    {
        cin >> a[i];
        num[a[i]]++;
        gongxu[i] = num[a[i]];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> no[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> ti[i][j];
    for (int i = 0; i < n * m; i++)
    {
        machine[no[a[i]][gongxu[i]]].fill(a[i], ti[a[i]][gongxu[i]]);
    }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 0; j < machine[i].end + 10; j++)
    //     {
    //         cout << machine[i].work[j];
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, machine[i].end);
    }
    cout << ans << endl;
    return 0;
}