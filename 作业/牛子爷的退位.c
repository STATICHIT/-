#include<stdio.h>
//自定义求数组中最大元素的函数
int maxa(int a[],int size)//数组下标内不要写范围
{
    int i,max;
    max=a[0];
    for(i=0; i<size; i++)
    {
        if(max<a[i])
        {
            max=a[i]; ///存在疑惑，为什么书上的
                      ///自定义数组中数组形参有下标
        }
    }
    return max;

}
//自定义判断数组中某函数是否唯一
int weiyi(int a[3],int n)//数组下标内不要写范围
{
    int k,t=1;
    for(k=0;k<3;k++)
    {
        if(n==k)
            {continue;}
        else
            if(a[n]==a[k])
            {t=0;
            break;}
    }
    return(t);
}
void main()
{
    int maxa(int a[],int size);
    int weiyi(int a[3],int i);
    int t,i,j,n;
    int a[3],b[3];
    scanf("%d",&n);
    for(j=0; j<n; j++)
    {
        for(i=0; i<3; i++)
        {
            scanf("%d",&a[i]);
        }
        //printf("max=%d\n",maxa(a,3));//检查maxa自定义函数功能
        /*int o=0;
        printf("weiyi=%d\n",weiyi(a,o));*///检查weiyi自定义函数功能
        for(i=0;i<3;i++)
        {
            if(a[i]==maxa(a,3)&&weiyi(a,i)==1)//调用函数时只写数组名
            {
                b[i]=0;
            }
            if(a[i]==maxa(a,3)&&weiyi(a,i)==0)
            {
                b[i]=1;
            }
            if(a[i]<maxa(a,3))
            {
            b[i]=maxa(a,3)-a[i]+1;
            }
        }
        for(i=0;i<3;i++)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
    }
}
