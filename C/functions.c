#include <stdio.h>

// Put your function prototypes up here
int add(int x, int y);

int main(void)
{
    int answer = add(5,4);
    printf("%d\n",answer);
    return 0;
}

// Either provide the body here, or put it in a library in a 
// separately compiled file
int add(int x, int y)
{
    return x + y;
}

// practice writing function prototypes
union Multi anything(struct Stuff s);

unsigned long long whatever(enum Rainbow bow);

