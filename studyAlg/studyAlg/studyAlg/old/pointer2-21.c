#include <stdio.h>
void print(int* x[], int no)
{
    for (int i = 0; i < no; i++)
        printf("x[%d] = %p, *x[%d] = %d\n", i, x[i], i, *x[i]);
}
int main(void)
{
    int a = 5, b = 3, c = 7;
    int* p[3]; 
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;

    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&c = %p, c = %d\n", &c, c);

    for(int i= 0 ; i < 3 ; i++)
        printf("p[%d] = %p, *p[%d] = %d\n", i, p[i], i, *p[i]);

    print(p, 3);
    return 0;
}

// &a = 00FEF920, a = 5
// &b = 00FEF914, b = 3
// &c = 00FEF908, c = 7

// p[0] = 00FEF920, *p[0] = 5
// p[1] = 00FEF914, *p[1] = 3
// p[2] = 00FEF908, *p[2] = 7

// x[0] = 010FF988, *x[0] = 5
// x[1] = 010FF97C, *x[1] = 3
// x[2] = 010FF970, *x[2] = 7