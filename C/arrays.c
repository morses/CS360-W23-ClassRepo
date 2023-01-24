#include <stdio.h>
#include <stdlib.h>

#define N 8

int arr1[N];

int main(void)
{
    int arr2[56];
    for(int i = 0; i < N; i++)
    {
        arr1[i] = 2*i;
    }

    for(int i = 0; i < N; i++)
    {
        printf("arr[%d] = %d\n",i,arr1[i]);
    }

    float * p_arr = (float *)malloc(100*sizeof(float));
    // pointer arithmetic
    *p_arr = 6.7;        // put 6.7 into  p_arr[0]
    *(p_arr + 1) = 45.4; // put 45.4 into p_arr[1]
    *(p_arr + 2) = 5.4;  // put 5.4 into p_arr[2]
    // or just use array notation ;-)
    p_arr[5] = 33.2;    // array variables are just pointers and vice versa
    free(p_arr);
}