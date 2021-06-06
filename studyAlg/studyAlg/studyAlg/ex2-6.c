#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
// x : 정수값
// n : 변환할 지수 
// d : 변환결과
// 역방향
int card_conv(unsigned x, int n, char d[])
{
    char    dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int     digits = 0; // 변환후의 글자수

    if (x == 0)
        d[digits++] = dchar[0];
    else
        while (x) {
            d[digits++] = dchar[x % n];
            x /= n;
        }
    return digits;
}
// 정방향
int card_conv_right(unsigned x, int n, char d2[])
{
    char    dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int     digits = 0; // 변환후의 글자수

    if (x == 0)
        d2[digits++] = dchar[0];
    else
    {
        int tmpX = x;
        do {
            digits++;
            tmpX /= n;
        } while (tmpX);
        
        for(int i = digits -1 ; i >= 0 ; i--)
        {
            d2[i] = dchar[x % n];
            x /= n;
        }
    }
    return digits;
}
int main(void)
{
    int         i;
    unsigned    no;         // 변환할 정수
    int         cd;         // 기수
    int         dno;        // 변환후의 글자수
    int         dno2;       // 변환후의 글자수
    char        cno[512];   // 변화후의 숫자를 보관할 변수
    char        cno2[512] = { 0 };  // 변화후의 숫자를 보관할 변수

    puts("10진수를 기수변환한다.");
    printf("변환할 정수 : ");
    scanf("%d", &no);
    do {
        printf("변환할 진수 ( 2 - 36 ) :");
        scanf("%d", &cd);
    } while (cd < 2 || cd > 36);

    printf("%d를 %d진수로 변환 \n", no, cd);
    dno = card_conv(no, cd, cno);
    printf("%d진수로는 역방향:[", cd);
    for (i = dno - 1; i >= 0; i--)
        printf("%c", cno[i]);
    printf("]이다.\n");
    
    dno2 = card_conv_right(no, cd, cno2);
    printf("%d진수로는 정방향:[", cd);
    for (i = dno2 - 1; i >= 0; i--)
        printf("%c", cno2[i]);
    printf("]이다.\n\n");

    return 0;
}