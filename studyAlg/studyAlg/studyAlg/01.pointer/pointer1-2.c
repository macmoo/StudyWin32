#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
int main(void)
{
    int  nx;
    int* pt;

    nx = 57;
    pt = &nx;

    printf(" nx의 값:%d\n", nx);
    printf("&nx의 값:%p\n", &nx);
    printf(" pt의 값:%p\n", pt);
    printf("*pt의 값:%d\n", *pt);
}
