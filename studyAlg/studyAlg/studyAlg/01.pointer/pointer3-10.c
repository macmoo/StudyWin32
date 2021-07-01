#include <stdio.h>

// 다차원배열을 받는 함수에서는 
// 가장선두의 첨자에 해당하는 요소수만이 가변이고
// 그외의 요소수는 고정이다.
void fill_avalue(int a[][3], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = i + j;
}
void print_arr(int a[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("a[%d][%d] = %d\t", i, j, a[i][j]);
        putchar('\n');
    }
}
int main(void)
{
    int mx[2][3];
    int my[4][3];

    fill_avalue(mx, 2);
    fill_avalue(my, 4);

    puts("-----mx-----");
    print_arr(mx, 2);

    puts("-----my-----");
    print_arr(my, 4);
    return 0;
}
// ---- - mx---- -
// a[0][0] = 0     a[0][1] = 1     a[0][2] = 2
// a[1][0] = 1     a[1][1] = 2     a[1][2] = 3
// ---- - my---- -
// a[0][0] = 0     a[0][1] = 1     a[0][2] = 2
// a[1][0] = 1     a[1][1] = 2     a[1][2] = 3
// a[2][0] = 2     a[2][1] = 3     a[2][2] = 4
// a[3][0] = 3     a[3][1] = 4     a[3][2] = 5
