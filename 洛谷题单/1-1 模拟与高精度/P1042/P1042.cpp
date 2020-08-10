#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 2500 * 25 + 5;

char a[maxn];

char read_char()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

int main()
{
    freopen("in.txt", "r", stdin);
    char ch = read_char();
    int len = 0;
    while (ch != 'E')
    {
        a[len++] = ch;
        ch = read_char();
    }
    int x = 0, y = 0;
    for (int i = 0; i < len; i++)
    {
        switch (a[i])
        {
        case 'W':
            x++;
            break;
        case 'L':
            y++;
            break;
        }
        if (abs(x - y) >= 2 && (x >= 11 || y >= 11))
        {
            printf("%d:%d\n", x, y);
            x = y = 0;
        }
    }
    if (x || y)
        printf("%d:%d\n\n", x, y);
    else if (len == 11)
        printf("0:0\n\n");
    x = y = 0;
    for (int i = 0; i < len; i++)
    {
        switch (a[i])
        {
        case 'W':
            x++;
            break;
        case 'L':
            y++;
            break;
        }
        if (abs(x - y) >= 2 && (x >= 21 || y >= 21))
        {
            printf("%d:%d\n", x, y);
            x = y = 0;
        }
    }
    if (x || y)
        printf("%d:%d\n", x, y);
    if (len == 0)
        printf("0:0\n\n0:0\n");
    return 0;
}