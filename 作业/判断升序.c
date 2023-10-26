#include<stdio.h>
int main()
{
    int a,b,c,d,s1,s2,s3,s4,sum;
    char isVip;
    printf("请分别输入A，B，C，D四件商品的数量：");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a>=2)
    {s1=200*a*0.8;}
    else
        {s1=200*a;}
    if(b=1)
    {s2=200*0.9;}
     else
     {s2=200*b*0.75;}
    s3=200*c*0.85;
    if(d<3)
    {s4=200*d*0.9;}
    else
    {s4=200*d*0.7;}

    sum=s1+s2+s3+s4;
    getchar();
    printf("一般会员请输入V,高级会员请输入v,普通顾客请输入其他字符：");
    scanf("%c"&isVip);
    if(V)
        sum=*0.7;
       if(v)
        sum=*0.6;
        else
            sum=*0.9;

    if(sum>1000)
    sum=(sum-1000)*0.7+1000;
    printf("%d",sum);
    return 0;
}
