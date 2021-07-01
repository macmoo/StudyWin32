#include <stdio.h>

// n1행 n2열의 2차배열의 전요소에 첨자의 합을 대입
int fill_avalue(int* a, int n1, int n2)
{
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            a[i * n2 + j] = i + j;
}
int main(void)
{
    int i, j;
    int mx[3][2];
    int my[4][4];
    fill_avalue(&mx[0][0], 3, 2);
    fill_avalue(&my[0][0], 4, 4);

    puts("-mx------------------");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%3d", mx[i][j]);
        putchar('\n');
    }
    puts("-my------------------");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d", my[i][j]);
        putchar('\n');
    }

    return 0;
}
// - mx------------------
// 0  1
// 1  2
// 2  3
// - my------------------
// 0  1  2  3
// 1  2  3  4
// 2  3  4  5
// 3  4  5  6