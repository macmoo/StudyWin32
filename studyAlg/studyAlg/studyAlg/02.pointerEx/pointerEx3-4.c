#include <stdio.h>

void fill_avalue(int a[][2][4], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 4; k++)
                a[i][j][k] = i + j + k;
}

void print_arr(int a[][2][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 4; k++)
                printf("%3d", a[i][j][k]);
            putchar('\n');
        }
    }
}

int main(void)
{
    int a[2][2][4];
    int b[4][2][4];

    fill_avalue(a, 2);
    fill_avalue(b, 4);

    puts("----a----");
    print_arr(a, 2);
    puts("----b----");
    print_arr(b, 4);

    return 0;
}

// ----a----
// 0  1  2  3
// 1  2  3  4
// 1  2  3  4
// 2  3  4  5
// ----b----
// 0  1  2  3
// 1  2  3  4
// 1  2  3  4
// 2  3  4  5
// 2  3  4  5
// 3  4  5  6
// 3  4  5  6
// 4  5  6  7
