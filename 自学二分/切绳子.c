#include<stdio.h>
int n,a[10005],l=0,r=0,num=0,k,mid;//设置全局变量
void in()
{
    scanf("%d %d",&n,&k);
    double c;
    for (int i=0; i<n; i++)
    {
        scanf("%lf",&c);
        a[i]=c*100;
        if (a[i]>r)
            r=a[i];//最后r为最长绳子长度
    }
    return;
}
void cpu()
{
    while (l<r)
    {
        mid=(l+r+1)/2;
        num=0;
        for (int i=0; i<n; i++)
            num+=a[i]/mid;
        if (num>=k)
            l=mid;
        else
            r=mid-1;
    }
    printf("%.2lf",r*0.01);//变回小数输出
    return;
}
int main()
{
    in();
    cpu();
    return 0;
}
