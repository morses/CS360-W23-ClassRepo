#include <stdio.h>
#include <stdlib.h>

struct point 
{
    int x;
    int y;
};

void foo(struct point * pt)
{
    pt->x = 100;
    pt->y = 200;
    printf("Inside foo: (pt.x,pt.y) = (%d,%d)\n",pt->x,pt->y);
}

int main(void)
{
    int a = 5;
    int * p_a = &a;
    printf("a   = %d address of   a = %p\n",a,&a);
    printf("p_a = %p address of p_a = %p\n",p_a,&p_a);
    *p_a = 67;
    printf("a   = %d address of   a = %p\n",a,&a);
    printf("p_a = %p address of p_a = %p\n",p_a,&p_a);
    struct point pt = {5,9};
    printf("(pt.x,pt.y) = (%d,%d)\n",pt.x,pt.y);
    // or
    // pt.x = 5;
    // pt.y = 9;
    foo(&pt);
    printf("(pt.x,pt.y) = (%d,%d)\n",pt.x,pt.y);

    // dynamic memory allocation
    struct point * p_pt = (struct point *)malloc(1*sizeof(struct point));
    printf("(p_pt->x,p_pt->y) = (%d,%d)\n",p_pt->x,p_pt->y);
    p_pt->x = 999;
    p_pt->y = 888;
    printf("(p_pt->x,p_pt->y) = (%d,%d)\n",p_pt->x,p_pt->y);

    free(p_pt);
}