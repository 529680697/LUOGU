#include <iostream>
#include <cstdio>

#define MAXN 100005

using namespace std;

int T, n, m;
int s[MAXN];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &s[i]);
        }
        }
    return 0;
}