#include <stdio.h>

void set123(int* a)
{
    *a = 1;
    *(a + 1) = 2;
    *(a + 2) = 3;
}
int main(void)
{
    int x[5];
    set123(x);

    printf("x[0] = %d\n", x[0]);
    printf("x[1] = %d\n", x[1]);
    printf("x[2] = %d\n", x[2]);
    
    return 0;
}