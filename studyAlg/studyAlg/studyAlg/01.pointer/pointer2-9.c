#include <stdio.h>

void func(int a[])
{
    printf("sizeof(a) = %u\n", (unsigned)sizeof(a));
}
int main(void)
{
    printf("-----------------------------\n");
    printf("■[2-09]                      \n");
    printf("-----------------------------\n");
    int x[5];
    printf("sizeof(x) = %u\n", (unsigned)sizeof(x));
    func(x);
    // sizeof(x) = 20
    // sizeof(a) = 4
    printf("-----------------------------\n");
    printf("■[2-10]                      \n");
    printf("-----------------------------\n");
    printf("x의 요소수는 %d이다\n", (unsigned)sizeof(x) / sizeof(x[0]));
    // x의 요소수는 5이다
    return 0;
}