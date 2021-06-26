#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
// 랜덤개의 랜덤값이 들어간 배열을 생성
//int*
void makeArr(int* arr)
{
    srand(time(NULL));
    int cnt = 5 + rand() % 10;

    arr = (int*)malloc(cnt * sizeof(int));
    memset(arr, 0, sizeof(int) * cnt);
    for (int i = 0; i < cnt; i++)
        arr[i] = rand() / 200;
    
    printf("count : %d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("arr[%d]:%d\n", i, arr[i]);
    return arr;
}
int main(void)
{
    int* arr = NULL;
    makeArr(arr);

    printf("main cnt ; %d \n", sizeof(arr));

    printf("arr[0]: % d \n", arr[0]);
    /*for (int i = 0; i < cnt; i++)
        printf("arr[%d]:%d\n", i, arr[i]);*/
}