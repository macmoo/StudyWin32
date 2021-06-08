#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>

int main(void)
{
    int nx = 100;
    int* pt = &nx;

    
    printf("int  형은 %u바이트이다.\n", (unsigned)sizeof(int));
    printf("int* 형은 %u바이트이다.\n", (unsigned)sizeof(int*));

    printf(" nx 는 %u바이트이다.\n", (unsigned)sizeof(nx));
    printf("*pt 는 %u바이트이다.\n", (unsigned)sizeof(*pt));
    printf(" pt 는 %u바이트이다.\n", (unsigned)sizeof(pt));
    printf("&nx 는 %u바이트이다.\n", (unsigned)sizeof(&nx));

    printf("------------------------\n");

    printf("&nx 는 %d 이다.\n", &nx);
    printf("*pt 는 %d 이다.\n", *pt);

    printf("*&nx 는 %d 이다.\n", *&nx);
    printf("&*pt 는 %d 이다.\n", &*pt);

    return 0;
} 