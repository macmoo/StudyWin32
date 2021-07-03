#include <stdio.h>

int main(void)
{
    char* p = "ABCD";
    char* q = '\0';

    printf("p : %s, addr = %p\n", p, p);
    printf("q : %s, addr = %p\n", q, q);
    puts("------------------");

    q = p;

    printf("p : %s, addr = %p\n", p, p);
    printf("q : %s, addr = %p\n", q, q);
    puts("------------------");
    p = "ZZZZ";
    printf("p : %s, addr = %p\n", p, p);
    printf("q : %s, addr = %p\n", q, q);
    puts("------------------");
    q = "YYYY";
    printf("p : %s, addr = %p\n", p, p);
    printf("q : %s, addr = %p\n", q, q);
    puts("------------------");
    return 0;
}
// p : ABCD, addr = 00467B30
// q : (null), addr = 00000000
// ------------------
// p : ABCD, addr = 00467B30
// q : ABCD, addr = 00467B30
// ------------------
// p : ZZZZ, addr = 00467C00
// q : ABCD, addr = 00467B30
// ------------------
// p : ZZZZ, addr = 00467C00
// q : YYYY, addr = 00467C08
// ------------------