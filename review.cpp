#include <iostream>
#include <cstdio>
using namespace std;
int a = 2;
int b = 3;

void func()
{
    b = 4;
}

int main()
{
    printf("%d\n", a + b);
    func();
    printf("%d\n", a + b);
}
