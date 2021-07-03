#include <stdio.h>

void arr_cpy(int a[], const int b[], int n)
{
    for (int i = 0; i < n; i++)
        // *(a+i) = b[i];  // OK
        a[i] = b[i];    // OK
}
int main(void)
{
    int  x[5] = { 11,22,33,44,55 };
    int  y[5];

    int cnt = sizeof(x) / sizeof(x[0]);
    arr_cpy(y, x, cnt);

    for (int i = 0; i < cnt; i++)
        printf("y[%d] = %d\n", i, y[i]);
    return 0;
}