#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
/* */
/* */
/* */
#include <stdio.h>
// x : 정수값
// n : 변환할 지수 
// d : 변환결과
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

int main(void)
{
    int         i;
    unsigned    no;         // 변환할 정수
    int         cd;         // 기수
    int         dno;        // 변환후의 글자수
    char        cno[512];   // 변화후의 숫자를 보관할 변수
    int         retry;

    puts("10진수를 기수변환한다.");
    printf("변환할 정수 : ");
    scanf("%d", &no);
    do {
        do {
            printf("변환할 진수 ( 2 - 36 ) :");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);

        printf("%d를 %d진수로 변환 \n", no, cd);
        dno = card_conv(no, cd, cno);

        printf("%d진수로는 [", cd);
        for (i = dno - 1; i >= 0; i--)
            printf("%c", cno[i]);
        printf("]이다.\n\n");
        printf("한번더? Yes(1)/No(0)");
        scanf("%d", &retry);
    } while (retry == 1);
    return 0;
}
