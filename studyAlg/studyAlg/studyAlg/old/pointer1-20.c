#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sort2(int* na, int* nb)
{
    if (*na > *nb)
        swap(na, nb);
}

int main(void)
{
    int a, b;
    puts("정수 두개를 입력하시오.");
    printf("정수A : ");
    scanf("%d", &a);
    printf("정수B : ");
    scanf("%d", &b);

    sort2(&a, &b);
    puts("정수 두개를 정렬한다.");
    printf("A의 값은 : %d\n", a);
    printf("B의 값은 : %d\n", b);
    return 0;
}