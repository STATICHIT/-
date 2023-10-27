#include<stdio.h>
void main()
{
    unsigned long long int a,b,c;///题目要求数据为正！整数
    while(~scanf("%llu %llu %llu",&a,&b,&c))
    {
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        if(a+b>c&&a+c>b&&b+c>a)

            printf("yes\n");

        else
            printf("no\n");
    }
}
