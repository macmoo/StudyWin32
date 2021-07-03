#include <stdio.h>

// 3차배열 요소수 계산
int main(void)
{
    int b[3][2][4] = {
        {{1,2,3,4},{5,6,7,8}},
        {{9,10,11,12},{13,14,15,16}},
        {{17,18,19,20},{21,22,23,24}}
    };

    
    printf("1 : %d\n", sizeof(b) / sizeof(b[0]));
    printf("2 : %d\n", sizeof(b[0]) / sizeof(b[0][0]));
    printf("3 : %d\n", sizeof(b[0][0]) / sizeof(b[0][0][0]));

   return 0;
}
// 1 : 3
// 2 : 2
// 3 : 4