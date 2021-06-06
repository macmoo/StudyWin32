#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// 랜덤개의 랜덤값이 들어간 배열을 생성
int makeArr(int* arr)
{
    srand(time(NULL));
    int count = 5 + rand() % 10;
    arr = (int*)malloc(count * sizeof(int));
    memset(arr, 0, sizeof(int) * count);
    for (int i = 0; i < count; i++)
        arr[i] = rand() / 200;
    
    printf("count : %d\n", count);
    for (int i = 0; i < count; i++)
        printf("arr[%d]:%d\n", i, arr[i]);
    return count;
}
int main(void)
{
    int* arr = NULL;
    int cnt = makeArr(arr);

    printf("main cnt ; %d \n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("arr[%d]:%d\n", i, arr[i]);
}