#include <stdio.h>

void foo(int * p);

int main(void)
{
    int a = 5;
    int * p_a = (int *)5;
    foo(p_a);
}