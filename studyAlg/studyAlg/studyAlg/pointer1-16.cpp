#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>

using namespace std;
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main(void)
{
    int a, b;
    cout << "두개의 정수를 입력하시오.\n";
    cout << "정수 A:";
    cin >> a;
    cout << "정수 B:";
    cin >> b;
    swap(a, b);

    cout << "스왑후\n";
    cout << "A : " << a << "이다.\n";
    cout << "B : " << b << "이다.\n";
}
