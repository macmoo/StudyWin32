#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>

int main(void)
{
    register int nx;
    printf("&nxÀÇ °ªÀº %p\n", &nx); // ERROR
    return 0;
}