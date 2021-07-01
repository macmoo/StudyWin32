#include <stdio.h>

int str_chnum(const char* s, int c)
{
    unsigned int count = 0;
    while (*s)
        if (*s++ == c)
            count++;
    return count;
}
int main(void)
{   
    char str[] = "abcaade";
    char c = 'a';
    printf("문자열 %s에는 문자%c가 %d개 포함되어있다.\n", str, c, str_chnum(str, c));
    return 0;
}

// 문자열 abcaade에는 문자a가 3개 포함되어있다.