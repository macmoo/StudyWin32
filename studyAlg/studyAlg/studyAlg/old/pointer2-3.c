#include <stdio.h>

int main(void)
{
    int i;
    int a[5];
    int* p = a; // p´Â a[0]À» °¡¸®Å´
    for (i = 0; i < 5; i++)
        printf("&a[%d] = %p, p+%d = %p\n", i, &a[i], i, p + i);
    return 0;
}

//&a[0] = 0113FC78, p + 0 = 0113FC78
//&a[1] = 0113FC7C, p + 1 = 0113FC7C
//&a[2] = 0113FC80, p + 2 = 0113FC80
//&a[3] = 0113FC84, p + 3 = 0113FC84
//&a[4] = 0113FC88, p + 4 = 0113FC88