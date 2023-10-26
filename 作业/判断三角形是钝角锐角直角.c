#include<stdio.h>

int main()

{
    int a,b,c;
    float q;

    scanf("%d,%d,%d",&a,&b,&c);
    q=(a*a+b*b-c*c)/(2*a*b);
    if(a+b>c&&a+c>b&&b+c>a)
        if(q>0)
            printf("ruijiao\n");
    if(q=0)
        printf("zhijiao\n");
    if(q<0)
        printf("dunjiao\n");
    else
        printf("wu\n");
    return 0;
}
