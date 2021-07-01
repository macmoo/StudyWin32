#include <stdio.h>

// 배열에 문자열 저장
int main(void)
{
    char str1[6];
    char str2[6];
    char str3[6];
    char str4[] = "ABCDE";

    str1[0] = 'A';
    str1[1] = 'B';
    str1[2] = 'C';
    str1[5] = '\0';
    printf("배열str1에는 문자열 \"%s\"가 저장되어 있다.\n", str1);

    str2[0] = 'Q';
    str2[1] = 'B';
    str2[2] = 'C';
    str2[3] = '\0';
    str2[4] = 'D';
    str2[5] = 'E';
    printf("배열str2에는 문자열 \"%s\"가 저장되어 있다.\n", str2);

    str3[0] = '\0';
    str3[1] = 'B';
    str3[2] = 'C';
    str3[3] = 'D';
    str3[4] = 'E';
    str3[5] = 'F';
    printf("배열str3에는 문자열 \"%s\"가 저장되어 있다.\n", str3);
    
    printf("배열str4에는 문자열 \"%s\"가 저장되어 있다.\n", str4);
    
    puts("* 사이즈 -------");
    printf("배열str1의 사이즈 : %u\n", (unsigned)sizeof(str1));
    printf("배열str2의 사이즈 : %u\n", (unsigned)sizeof(str2));
    printf("배열str3의 사이즈 : %u\n", (unsigned)sizeof(str3));
    printf("배열str4의 사이즈 : %u\n", (unsigned)sizeof(str4));

    puts("* 주소 ---------");
    printf("배열str1의 주소 : %p\n", str1);
    printf("배열str2의 주소 : %p\n", str2);
    printf("배열str3의 주소 : %p\n", str3);
    printf("배열str4의 주소 : %p\n", str4);

    return 0;
}
// 배열str에는  문자열 "ABC儆"가 저장되어 있다.
// 배열str2에는 문자열 "QBC"가 저장되어 있다.
// 배열str3에는 문자열 ""가 저장되어 있다.