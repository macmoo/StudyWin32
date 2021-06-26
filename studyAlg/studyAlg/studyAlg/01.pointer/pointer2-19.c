#include <stdio.h>
// ¼±ÇüÅ½»ö
int seq_search1(int* x, int n, int no)
{
    for (int i = 0; i < n; i++)
        if (*x++ == no)
            return (i);
    return -1;
}

int seq_search1(int* x, int n, int no)
{
    int* p = x;
    while (n-- > 0)
    {
        if (*p == no)
            return p - x;
        else
            p++;
    }
    return (-1);
}
