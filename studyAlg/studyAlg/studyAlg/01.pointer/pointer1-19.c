#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>

int main(void)
{
    int     i;
    long    k;
    char    s[20];

    printf("정수를 입력해라.:");
    scanf("%d", &i);

    printf("정수를 입력해라.:");
    scanf("%ld", &k);

    printf("문자열을 입력해라.");
    scanf("%s", s);

    printf("정수   i 의 입력값은 : %d이다.\n", i);
    printf("정수   k 의 입력값은 : %ld이다.\n", k);
    printf("문자열 s 의 입력값은 : %s이다.\n", s);

    return 0;
}
