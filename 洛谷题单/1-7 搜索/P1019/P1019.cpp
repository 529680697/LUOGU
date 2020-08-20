#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, vis[30], go[30][30];
string s[30];
int ans = 0;

void dfs(int x, int dis)
{
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] < 2 && go[x][i])
        {
            vis[i]++;
            ans = max(ans, dis + go[x][i]);
            dfs(i, dis + go[x][i]);
            vis[i]--;
        }
    }
}

inline int count_go(int a, int b)
{
    if (a == 0 && s[a][0] == s[b][0])
    {
        // cout << s[a][0] << s[b][0] << endl;
        return s[b].length();
    }
    int max_len = 0;
    for (int i = 1; i < s[a].length();)
    {
        if (s[a][i] == s[b][0])
        {
            int j;
            for (j = 1; j < s[b].length() && i + j < s[a].length(); j++)
            {
                if (s[a][i + j] != s[b][j])
                    break;
            }
            if (j < s[b].length() && i + j == s[a].length())
            {
                max_len = s[b].length() - j;
                i++;
            }
            else
            {
                i += j;
            }
        }
        else
            i++;
    }
    return max_len;
}

int main()
{
    char a;
    ios::sync_with_stdio(false);
    freopen("in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    cin >> s[0];
    // s[0] = a;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        // if (i != j)
        {
            go[i][j] = count_go(i, j);
            // cout << count_go(i, j) << " ";
        }
        // cout << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i][0] == a)
    dfs(0, 0);
    // }
    cout << ans << endl;
    return 0;
}