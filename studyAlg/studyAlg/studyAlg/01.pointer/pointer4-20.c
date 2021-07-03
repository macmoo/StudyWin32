#include <stdio.h>

unsigned int lengOfString(const char* t)
{
    unsigned int count = 0;
    while (*t++ != '\0')
        count++;
    return count;
}
void put_str(const char* s)
{
    while (*s)
    // or while (*s != '\0')
        putchar(*s++);
    putchar('\n');
}
int main(void)
{
    // 배열에 의한 문자열
    char str[] = "ABCDEF";   // str의 각요소는 'A','B','C','\n'
    // 포인터에 의한 문자열
    char* ptr  = "XYZ1234";  // ptr의 각요소는 'X','Y','Z'

    printf("문자열 str은 \"%s\"이다.\n", str);
    printf("문자열 ptr은 \"%s\"이다.\n", ptr);

    printf("문자열 str의 사이즈 \"sizeof(%s)\"는 %u이다.\n", str, (unsigned)sizeof(str));
    // ptr의 사이즈는 포인터ptr의 사이즈(4) + 리터럴"XYZ1234"가 되어야 한다. 이하는 NG.
    printf("문자열 ptr의 사이즈 \"sizeof(%s)\"는 %u이다.\n", ptr, (unsigned)sizeof(ptr));
    
    printf("문자열 str의 길이 \"length(%s)\"는 %u이다.\n", str, lengOfString(str));
    printf("문자열 ptr의 길이 \"length(%s)\"는 %u이다.\n", ptr, lengOfString(ptr));
   
    // []접근가능
    putchar(str[1]);  putchar('\n');
    putchar(ptr[1]);  putchar('\n');

    // 출력
    puts("str 출력"); put_str(str);
    puts("ptr 출력"); put_str(ptr);

    // 차이점
    // ↓ ERROR : 오류	C2106	'=': 왼쪽 피연산자는 l - value이어야 합니다.
    // str = "XXXXXX"; 
    ptr = "XXXXXX"; // OK
    puts("ptr 출력"); put_str(ptr);

    return 0;
}

// 문자열 str은 "ABCDEF"이다.
// 문자열 ptr은 "XYZ1234"이다.
// 문자열 str의 사이즈 "sizeof(ABCDEF)"는 7이다.
// 문자열 ptr의 사이즈 "sizeof(XYZ1234)"는 4이다.
// 문자열 str의 길이 "length(ABCDEF)"는 6이다.
// 문자열 ptr의 길이 "length(XYZ1234)"는 7이다.
// B
// Y
// str 출력
// ABCDEF
// ptr 출력
// XYZ1234
// ptr 출력
// XXXXXX