#include <stdio.h>

// 배열에 대해 &를 적용하면 
// 배열의 선두요소에 대한 포인터가 아니라
// 배열전체에 대한 포인터가 된다.
int main(void)
{
    int x[5] = { 1,2,3,4,5 };

    //  x는 x[0]에의 포인터
    // &x는 배열전체에의 포인터
    printf("sizeof(*&x)     = %u\n", (unsigned)sizeof(*&x));
    printf("sizeof(*&x[0])  = %u\n", (unsigned)sizeof(*&x[0]));
    
    printf("*&x     = %d\n", *&x);
    printf("*&x[0]  = %d\n", *&x[0]);
    return 0;
}