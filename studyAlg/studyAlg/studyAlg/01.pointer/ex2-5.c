#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
// "do{ } while();" 가 세트
// (호출시의 swap에 맨뒤에 ;가 있으니 중복됨 그래서 define에선 생략)
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)
// 배열 출력
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}
// n개의 배열a의 요소를 반전
void arr_reverse(int a[], int n)
{
    int i;
    for (i = 0; i < n / 2; i++) 
    {
        printArr(a, n);
        printf("a[%d]과 a[%d]를 교환합니다.\n", i, n - i - 1);
        swap(int, a[i], a[n - i - 1]);
    }
}
int main(void)
{
    int i;
    int* arr;
    int num;

    printf("요소수 :");
    scanf("%d", &num);

    arr = calloc(num, sizeof(int));
    for (i = 0; i < num; i++)
    {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }

    arr_reverse(arr, num); // 반전

    printf("-- 출력 --\n");
    for (i = 0; i < num; i++)
        printf("arr[%d]:%d\n", i, arr[i]);

    free(arr);
    return 0;
}