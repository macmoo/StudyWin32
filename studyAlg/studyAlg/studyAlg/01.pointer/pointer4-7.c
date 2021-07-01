#include <stdio.h>

int main(void)
{
    printf("문자열 \"ABCD\"    = %p\n", "ABCD"); // 문자열의 주소
    printf("문자열 \"ABCD\"    = %s\n", "ABCD"); // 문자열 출력
    
    printf("문자열 \"AB\\0CD\"  = %p\n", "AB\0CD");
    printf("문자열 \"AB\\0CD\"  = %s\n", "AB\0CD");
    printf("sizeof(\"AB\\0CD\") = %u\n", (unsigned)sizeof("AB\0CD"));
    return 0;
}

// 문자열 "ABCD"    = 00D67B30
// 문자열 "ABCD"    = ABCD
// 문자열 "AB\0CD"  = 00D67B58
// 문자열 "AB\0CD"  = AB
// sizeof("AB\0CD") = 6