#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <limits.h>
int main(void)
{
    printf("1바이트는 %d비트다\n", CHAR_BIT);
    return 0;
}
