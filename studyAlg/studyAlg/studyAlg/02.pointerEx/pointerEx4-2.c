#include <stdio.h>

int main(void)
{
    char str[100];
    puts("문자열을 입력하라:");
    scanf("%s", str);
    printf("입력한 문자열 : %s\n", str);

    return 0;
}