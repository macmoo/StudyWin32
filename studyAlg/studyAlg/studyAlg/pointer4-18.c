#include <stdio.h>
char* str_copy(char* d, const char* s)
{
    char* p = d;
    while (*d++ = *s++);
    return (p);
}
int main(void)
{
    char tmp[100];
    char st1[100], st2[100], st3[100];

    printf("문자열을 입력하시오:");
    scanf("%s", tmp);

    // st1에 복사한 문자열을 st2에도 복사함
    str_copy(st1, str_copy(st2, tmp));

    printf("문자열 st1은 \"%s\"이다.\n", st1);
    printf("문자열 st2은 \"%s\"이다.\n", st2);
    printf("문자열 st3은 \"%s\"이다.\n", str_copy(st3, tmp));

    return 0;
}
// 문자열을 입력하시오 : aaaaa
// 문자열 st1은 "aaaaa"이다.
// 문자열 st2은 "aaaaa"이다.
// 문자열 st3은 "aaaaa"이다.