#include <stdio.h>
#include <ctype.h> // isdigit

int str_dignum(const char* s)
{
    int count = 0;
    while (*s)
    {
        if (*s > '0' && *s < '9')
            count++;
        s++;
    }
    return count;
}
int str_dignum2(const char* s)
{
    int count = 0;
    while (*s)
    {
        if (isdigit(*s))
            count++;
        s++;
    }
    return count;
}
int main(void)
{
    char str[] = "a1b2c3a4a5d6e";
    printf("1) 문자열 %s에는 숫자가 %d개 포함되어있다.\n", str, str_dignum(str));
    printf("2) 문자열 %s에는 숫자가 %d개 포함되어있다.\n", str, str_dignum2(str));
    return 0;
}

// 1) 문자열 a1b2c3a4a5d6e에는 숫자가 6개 포함되어있다.
// 2) 문자열 a1b2c3a4a5d6e에는 숫자가 6개 포함되어있다.