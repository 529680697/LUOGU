#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long dp[22][2], c[22][22], sum;

int main()
{
    //计算组合数
    for (int i = 0; i < 21; i++)
    {
        c[i][0] = c[i][i] = 1;
    }
    for (int i = 2; i < 21; i++)
    {
        for (int j = 0; j <= i / 2; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][i - j] = c[i][j];
        }
    }
    dp[0][0] = dp[0][1] = 1;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < 21; i++)
    {
        sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum += dp[j][1] * dp[i - j - 1][0] * c[i - 1][j];
        }
        dp[i][0] = dp[i][1] = sum >> 1;
    }
    cin >> n;
    int num, i;
    while (n--)
    {
        cin >> num >> i;
        cout << num << " ";
        if (i == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << dp[i][1] + dp[i][0] << endl;
        }
    }
    return 0;
}