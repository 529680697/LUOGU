#include <stdio.h>

char cube[7][8] = {
    "  +---+",
    " /   /|",
    "+---+ |",
    "|   | +",
    "|   |/",
    "+---+",
};
char flag[1001][1001];
int from[6] = {0, 0, 0, 0, 1, 2};
int end[6] = {4, 5, 6, 6, 6, 6};

void place(int x, int y)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = from[i]; j <= end[i]; j++)
        {
            flag[x + i][y + j] = cube[5 - i][j];
        }
    }
}

int main()
{
    int m, n, max_x = 0, max_y = 0;
    int h[55][55]; //记录布局中立方体的高度
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &h[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < h[i][j]; k++)
            {
                int y = 2 * (n - i) + 4 * (j - 1);
                int x = 2 * (n - i) + 3 * k;
                if (x > max_x)
                {
                    max_x = x;
                }
                if (y > max_y)
                {
                    max_y = y;
                }
                place(x, y);
            }

    for (int i = max_x + 5; i >= 0; i--)
    {
        for (int j = 0; j <= max_y + 6; j++)
        {
            if (flag[i][j] == '\000')
                printf(".");
            else
                printf("%c", flag[i][j]);
        }
        printf("\n");
    }
    return 0;
}