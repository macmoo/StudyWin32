#include <stdio.h>

// 3차배열 사이즈 계산
int main(void)
{
    int a[3][2][4] = {
        {{1,2,3,4},{5,6,7,8}},
        {{9,10,11,12},{13,14,15,16}},
        {{17,18,19,20},{21,22,23,24}}
    };

    printf("1 sizeof(int)        : %u\n", sizeof(int));
    printf("2 sizeof(a)          : %u\n", sizeof(a));
    printf("3 sizeof(*a)         : %u\n", sizeof(*a));
    printf("4 sizeof(a[0])       : %u\n", sizeof(a[0]));
    printf("5 sizeof(a[0][0])    : %u\n", sizeof(a[0][0]));
    printf("6 sizeof(a[0][0][0]) : %u\n", sizeof(a[0][0][0]));

    return 0;
}
// 1 sizeof(int)        :  4
// 2 sizeof(a)          : 96
// 3 sizeof(*a)         : 32
// 4 sizeof(a[0])       : 32
// 5 sizeof(a[0][0])    : 16
// 6 sizeof(a[0][0][0]) :  4
