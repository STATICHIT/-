#include<stdio.h>
void main()
{
    unsigned long long int a,b,c;///��ĿҪ������Ϊ��������
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
