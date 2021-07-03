#include <stdio.h>

// 문자열에서 문자 검색
char* str_chr(const char* s, int c)
{
    c = (char)c;
    while (*s != c) {
        if (*s == '\0')
            return NULL;
        s++;
    }
    return ((char*)s);
}

int main(void)
{
    char* ptr;
    char  ch[2];
    char  letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printf("영대문자를 입력하시오:");
    scanf("%s", ch);

    if ((ptr = str_chr(letter, ch[0])) == NULL)
        printf("%c는 영대문자가 아닙니다.\n", ch[0]);
    else
        printf("%c에서 뒤의 알파벳은 %s이다.\n", ch[0], ptr);

    return 0;
}
// 영대문자를 입력하시오 : T
// T에서 뒤의 알파벳은 TUVWXYZ이다.
