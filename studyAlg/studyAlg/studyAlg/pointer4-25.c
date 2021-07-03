#include <stdio.h>

int main(void)
{
    // -----------------------------
    // 4-25
    char str[] = "ABC";
    char* ptr  = "XYZ";
    
    str[1] = 'Q';
    // 문자열 리터럴의 값은 바꾸지마라
    // 문자열 리터럴이 정수인지는 환경에 따라 다름.
    // ptr[1] = 'Q'; // ERROR 

    printf("str : %s\n", str);
    printf("ptr : %s\n", ptr);

    return 0;
}
// str : AQC
// ptr : XYZ