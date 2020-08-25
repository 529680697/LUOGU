#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b;
unsigned long long P[51][51], ans;
//注意注意, 一定要开unisigned long long, 这个卡住我最后一个点
void Work(int n)
{ //杨辉三角求组合数
    for (int i = 0; i <= n; ++i)
        P[i][0] = P[i][i] = 1; //两边赋初值1
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            P[i][j] = P[i - 1][j] + P[i - 1][j - 1]; //利用性质求组合数
}
int main()
{
    freopen("in", "r", stdin);
    cin >> n >> a >> b;          //读入
    Work(n + max(a, b));         //因为下面最大的组合数是n+a-1或者n+b-1
    for (int i = 0; i <= a; ++i) //要从0开始, 因为有都不放的情况
        for (int j = 0; j <= b; ++j)
            ans += P[n + i - 1][n - 1] * P[n + j - 1][n - 1]; //每个结果相加
    cout << ans;                                              //输出
    return 0;                                                 //好习惯
}