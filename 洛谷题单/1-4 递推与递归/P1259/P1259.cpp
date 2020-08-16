#include <iostream>
#include <cstdio>

using namespace std;

int n;
char a[4][16] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n;
    int i, j;
    for (i = n, j = 0; i >= 4;)
    {
        for (int k = 0; k < i; k++)
            putchar('o');
        for (int k = 0; k < i; k++)
            putchar('*');
        putchar('-'), putchar('-');
        for (int k = 0; k < j; k++)
            putchar('o'), putchar('*');
        putchar('\n');
        i--, j++;
        for (int k = 0; k < i; k++)
            putchar('o');
        putchar('-'), putchar('-');
        for (int k = 0; k < i; k++)
            putchar('*');
        for (int k = 0; k < j; k++)
            putchar('o'), putchar('*');
        putchar('\n');
    }
    for (int k = 0; k < 4; k++)
    {
        printf("%s", a[k]);
        for (int l = 0; l < j - 1; l++)
            putchar('o'), putchar('*');
        putchar('\n');
    }
    return 0;
}