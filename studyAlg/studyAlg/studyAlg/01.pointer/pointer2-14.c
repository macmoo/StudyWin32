#include <stdio.h>

int main(void)
{
    int nm = 1;
    const int nc = 2;

    // p1 is a pointer to an int.
    int* p1;
    
    // p2 is a pointer to an int const.
    // p2 is a pointer to a  const int.
    const int* p2; // == int const* p2;

    // p3m is a const pointer to an int.
    int* const p3m = &nm;
    int* const p3c = &nc;

    // p4m is a const pointer to an const int.
    const int* const p4m = &nm;
    const int* const p4c = &nc;

    nm = 100;    // ok
    // nc = 100; // error

    // --------------------------------------
    // p1 -----------------------------------
     p1 = &nm;  // ok
    *p1 = 100;  // ok
     p1 = &nc;  // ok
    *p1 = 99;   // 미정의
    printf("[1] -> *p1 = [%d], p1 = [%p]\n", *p1, p1);
    printf("[2] -> *p1 = [%d], p1 = [%p]\n", *p1, p1);
    printf("[3] -> *p1 = [%d], p1 = [%p]\n", *p1, p1);
    printf("[4] -> *p1 = [%d], p1 = [%p]\n", *p1, p1);
    //[1] -> * p1 = [100], p1 = [0135FDD0]
    //[2] -> * p1 = [100], p1 = [0135FDD0]
    //[3] -> * p1 = [2]  , p1 = [0135FDC4]
    //[4] -> * p1 = [99] , p1 = [0135FDC4]
    
    // --------------------------------------
    // p2 -----------------------------------
    p2 = &nm;      // ok
    // *p2 = 100;  // error
    p2 = &nc;      // ok
    // *p2 = 100;  // error

    // --------------------------------------
    // p3 -----------------------------------
    // p3m = &nm; // error
    // p3c = &nc; // error
    *p3m = 100;   // OK
    *p3c = 101;   // 미정의 
    printf("[5] -> *p3m = [%d], p3m = [%p]\n", *p3m, p3m);
    printf("[6] -> *p3c = [%d], p3c = [%p]\n", *p3c, p3c);
    // [5] -> * p3m = [100], p3m = [00EFFDAC]
    // [6] -> * p3c = [101], p3c = [00EFFDA0]

    // --------------------------------------
    // p4 -----------------------------------
    //  p4m = &nm;  // error
    //  p4c = &nc;  // error
    // *p4m = 100;  // error
    // *p4c = 101;  // error 
    return 0;
}