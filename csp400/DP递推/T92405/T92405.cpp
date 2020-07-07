#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, k;
double a[101][101];

int main()
{
    for (int i = 1; i < 101; i++)
    {
        a[i][0] = pow(2.0, (double)i);
        a[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            for (int k = 1; k <= j; k++)
            {
                a[i][j] += a[i - k][j];
            }
            a[i][j] += a[i - j][0];
        }
    }
    while (scanf("%d%d", &n, &k))
    {
        printf("%.0lf\n", a[n][k]);
    }
    return 0;
}