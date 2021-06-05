#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 최대값
int maxOf(const int a[], int n)
{
    int i;
    int max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}
// 최소값
int minOf(const int a[], int n)
{
    int i;
    int min = a[0];
    for (i = 1; i < n; i++)
        if (a[i] < min) min = a[i];
    return min;
}
// 합계
int sumOf(const int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}
// 평균
float aveOf(const int a[], int n)
{
    return (float)sumOf(a, n) / n;
}
int main(void)
{
    int i;
    int* height; // 배열의 선두요소의 포인터
    int num;

    printf("요소수 :");
    scanf("%d", &num);

    height = calloc(num, sizeof(int));
    // 시간으로 난수의 시드를 초기화
    srand(time(NULL));
    for (i = 0; i < num; i++)
    {
        // 100 ~ 189의 난수 생성
        height[i] = 100 + rand() % 90;
        printf("height[%d]:%d\n", i, height[i]);
    }
    printf("-- 출력 --\n");
    printf("최대값은 :%d\n", maxOf(height, num));
    printf("최소값은 :%d\n", minOf(height, num));
    printf("합계는   :%d\n", sumOf(height, num));
    printf("평균은   :%.3f\n", aveOf(height, num));
    free(height);
    return 0;
}