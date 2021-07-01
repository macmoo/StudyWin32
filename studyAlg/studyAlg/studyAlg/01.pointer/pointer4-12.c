#include <stdio.h>

unsigned str_length(const char s[])
{
    unsigned len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}
unsigned str_length2(const char s[])
{
    unsigned len = 0;
    for( ; *s != '\0' ; s++)
        len++;
    return len;
}
unsigned str_length3(const char s[])
{
    const char* p = s;
    while(*s)
        s++;
    return (s - p);
}
int main(void)
{
    char str[100];
    printf("문자열입력:");
    scanf("%s", str);

    printf("1) 문자열 %s의 길이는 %u이다.\n", str, str_length(str));
    printf("2) 문자열 %s의 길이는 %u이다.\n", str, str_length2(str));
    printf("3) 문자열 %s의 길이는 %u이다.\n", str, str_length3(str));

    return 0;
}
// 문자열입력:abcde
// 1) 문자열 abcde의 길이는 5이다.
// 2) 문자열 abcde의 길이는 5이다.
// 3) 문자열 abcde의 길이는 5이다.