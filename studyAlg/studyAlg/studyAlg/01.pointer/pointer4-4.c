#include <stdio.h>

int main(void)
{
    printf("sizefof(char)            : %u\n", (unsigned)sizeof(char));
    printf("sizefof(\"\")            : %u\n", (unsigned)sizeof(""));
    printf("sizefof(\"opq\")         : %u\n", (unsigned)sizeof("opq"));
    printf("sizefof(\"rs\\tt\")      : %u\n", (unsigned)sizeof("rs\tt"));
    printf("sizefof(\"uvw\\0xyz\")   : %u\n", (unsigned)sizeof("uvw\\0xyz"));

    return 0;
}

// sizefof(char)       : 1
// sizefof("")         : 1
// sizefof("opq")      : 4
// sizefof("rs\tt")    : 5
// sizefof("uvw\0xyz") : 9