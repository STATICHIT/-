/*
#include<stdio.h>
int pd1(int n)
{
    int i;
    for(i=2;i<n;i++)
        if(n%i == 0)
            break;
    if(i == n)
    return 1;//返回1说明是素数
    else
        return 0;
}
int pd2(int n)//要判断的是10到100，易知10和100不是会长数，所以n为两位数
{
 int shi,ge;
 ge=n%10;
 shi=n/10;
 if(pd1(ge) == 1&&pd1(shi) == 1&&pd1(shi+ge) == 1)
        return 1;
 else
    return 0;
}
int main()
{
    int i;
    for(i=10;i<100;i++)
    {
        if(pd1(i) == 1&&pd2(i) == 1)
            printf("%d",i);
    }
    printf("\n");
    return 0;
}
*/
