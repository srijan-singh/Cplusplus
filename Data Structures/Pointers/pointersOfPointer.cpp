#include <stdio.h>

int main()
{
    int a = 10;
    int *p;
    p = &a;
    int **q;
    q = &p;
    int ***r;
    r = &q;
    printf("value of a = %d\nvalue at p = %d\nvalue at q = %d\nvalue at r = %d\n",a,p,q,r);
    printf("value of a = %d\nvalue at *p = %d\nvalue at *q = %d\nvalue at *r = %d\n",a,*p,*q,*r);
    printf("value of a = %d\nvalue at *p = %d\nvalue at **q = %d\nvalue at ***r = %d\n",a,*p,**q,***r);

    ***r += 2;

    printf("value of a = %d\n", a);

    **q = *p + 2;

    printf("value of a = %d", a);

}