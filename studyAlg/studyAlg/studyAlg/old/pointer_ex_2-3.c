#include <stdio.h>
#define swap(type, x, y) do { type temp = x; x = y; y = temp; } while(0);
void sort_ptr3ary(int* x[])
{
    int temp;
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            if (*x[i] > *x[j])
            {
                temp = *x[i];
                *x[i] = *x[j];
                *x[j] = temp;
            }
}

void sort_ptr3ary_reverse(int* x[])
{
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            if (*x[i] < *x[j])
                swap(int*, x[i], x[j]);
}

int main(void)
{
    int a = 111;
    int b = 22;
    int c = 33;
    int* x[3];
    
    x[0] = &a;
    x[1] = &b;
    x[2] = &c;

    printf("BEFORE -------\n");
    for (int i = 0; i < 3; i++)
        printf("x[%d] = %p, *x[%d] = %d\n", i, x[i], i, *x[i]);
    
    sort_ptr3ary(x);

    printf("AFTER1 -------\n");
    for (int i = 0; i < 3; i++)
        printf("x[%d] = %p, *x[%d] = %d\n", i, x[i], i, *x[i]);

    sort_ptr3ary_reverse(x);
    printf("AFTER2 -------\n");
    for (int i = 0; i < 3; i++)
        printf("x[%d] = %p, *x[%d] = %d\n", i, x[i], i, *x[i]);

   return 0;
}

// BEFORE------ -
// x[0] = 00CFF714, *x[0] = 111
// x[1] = 00CFF708, *x[1] = 22
// x[2] = 00CFF6FC, *x[2] = 33
// AFTER1------ -
// x[0] = 00CFF714, *x[0] = 22
// x[1] = 00CFF708, *x[1] = 33
// x[2] = 00CFF6FC, *x[2] = 111
// AFTER2------ -
// x[0] = 00CFF6FC, *x[0] = 111
// x[1] = 00CFF708, *x[1] = 33
// x[2] = 00CFF714, *x[2] = 22