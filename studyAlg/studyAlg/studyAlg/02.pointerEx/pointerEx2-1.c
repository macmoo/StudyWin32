#include <stdio.h>

int main(void)
{
    int i;
    int a[5];
    int* p = &a[2]; // p´Â a[2]À» °¡¸®Å´
    for (i = 0; i < 5; i++)
        printf("&a[%d] = %p, p+%d = %p\n", i, &a[i], i, p + i);

    printf("&a[0] = %p, &0[a] = %p\n", &a[0], &0[a]);

    return 0;
}

// &a[0] = 001AF89C, p + 0 = 001AF8A4
// &a[1] = 001AF8A0, p + 1 = 001AF8A8
// &a[2] = 001AF8A4, p + 2 = 001AF8AC
// &a[3] = 001AF8A8, p + 3 = 001AF8B0
// &a[4] = 001AF8AC, p + 4 = 001AF8B4

// &a[0] = 003CF948, & 0[a] = 003CF948
