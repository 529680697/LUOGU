#include <iostream>

using namespace std;

struct node
{
    int num, sum;
} a[1005][1005];

int r;

int main()
{
    cin >> r;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j].num;
    for (int i = 1; i <= r; i++) //初始化最后一层
        a[r][i].sum = a[r][i].num;

    for (int i = r - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j].sum = a[i][j].num + (a[i + 1][j].sum > a[i + 1][j + 1].sum ? a[i + 1][j].sum : a[i + 1][j + 1].sum);
        }
    }
    cout << a[1][1].sum << endl;
    return 0;
}