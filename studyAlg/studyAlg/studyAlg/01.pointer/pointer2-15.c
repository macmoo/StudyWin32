#include <stdio.h>

// 배열x의 선두 n개의 요소에 0을 대입
// 포인터 a가 가리키고 있는건 배열이 아니라 요소이므로.
// 함수간에 배열을 넘길때는 배열의 갯수를 같이 넘겨야함
void fill_zero(int x[], int n)
{
    for (int i = 0; i < n; i++)
        x[i] = 1;
}

void fill_zero2(int x[], int n)
{
    for (int i = 0; i < n; i++)
        *(x + i) = 2;
}

void fill_zero3(int x[], int n)
{
    while (n-- > 0) {
        *x = 3;
        x++;
    }
}
void fill_zero4(int x[], int n)
{
    while (n-- > 0) 
        *x++ = 4;
}
int main(void)
{
    int a[5] = { 10,20,30,40,50 };
    int a_size = sizeof(a) / sizeof(a[0]); // 요소수

    fill_zero(a, a_size);
    for (int i = 0; i < a_size; i++)
        printf("a[%d] = %d\n", i, a[i]);

    printf("---------\n");
    fill_zero2(a, a_size);
    for (int i = 0; i < a_size; i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("---------\n");
    fill_zero3(a, a_size);
    for (int i = 0; i < a_size; i++)
        printf("a[%d] = %d\n", i, a[i]);
    printf("---------\n");
    fill_zero4(a, a_size);
    for (int i = 0; i < a_size; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}