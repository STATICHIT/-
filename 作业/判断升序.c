#include<stdio.h>
int main()
{
    int a,b,c,d,s1,s2,s3,s4,sum;
    char isVip;
    printf("��ֱ�����A��B��C��D�ļ���Ʒ��������");
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
    printf("һ���Ա������V,�߼���Ա������v,��ͨ�˿������������ַ���");
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
