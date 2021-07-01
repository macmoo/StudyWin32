#include <stdio.h>

void str_copy(char d[], const char s[])
{
    int i = 0;
    while ((d[i] = s[i]) != '\0')
        i++;
}
void str_copy2(char* d, const char* s)
{
    while (*d++ = *s++);
    // while ((*d++ = *s++) != '\0');  // OK
}
int main(void)
{
    char str[100] = "ABC";
    char tmp[100];
    char tmp2[100];

    printf("문자열 str은 \"%s\"입니다.\n", str);
    
    printf("1) 복사할 문자열을 입력하시오:");
    scanf("%s", tmp);
    str_copy(str, tmp);
    printf("1) 문자열 str은 \"%s\"입니다.\n", str);

    printf("2) 복사할 문자열을 입력하시오:");
    scanf("%s", tmp2);
    str_copy2(str, tmp2);
    printf("2) 문자열 str은 \"%s\"입니다.\n", str);


    return 0;
}
// 문자열 str은 "ABC"입니다.
// 1) 복사할 문자열을 입력하시오 : qwer
// 1) 문자열 str은 "qwer"입니다.
// 2) 복사할 문자열을 입력하시오 : 1234
// 2) 문자열 str은 "1234"입니다.