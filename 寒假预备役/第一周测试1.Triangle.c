#include<stdio.h>
int check(int a, int b, int c)
{
    if(a+b>c&&a+c>b&&b+c>a)
        return 1;
    else if(a+b>=c||a+c>=b||b+c>=a)
        return 2;
    else
        return 3;
}
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(check(a,b,c)==1||check(a,c,d)==1||check(a,b,d)==1||check(b,c,d)==1)
    printf("TRIANGLE");
    else if(check(a,b,c)==2||check(a,c,d)==2||check(a,b,d)==2||check(b,c,d)==2)
        printf("SEGMENT");
        else
            printf("IMPOSSIBLE");
    return 0;
}
