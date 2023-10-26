#include<stdio.h>
int main()
{
    int n,i,j,sum,hang;
    float aver;
    scanf("%d",&n);
    int a[n+1][n+1];
    float v[n+1];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        sum=0;
        for(j=0; j<n; j++)
        {
            sum=sum+a[i][j];
        }
        aver=sum*1.0/n;
        v[i]=aver;
    }
    /*for(i=0;i<n;i++)
    {printf("%f\n",v[i]);}//检查平均值计算*/
    float min=-1.0;///先设置两个数组两边取不到的数min和neww
    for(i=0; i<n; i++)//有n次输出
    {
        float neww=9999.0;///min循环后会改变从而丢掉输出的行数
        ///而neww要恢复很大的值让内循环第一次正常进行
        for(j=0; j<n; j++)
        {
            if(v[j]>min&&v[j]<neww )//此处的v[j]<min，
                //是要丢掉上一个最小值来排序
            {
                neww=v[j];//为下一次判断缩小范围
                hang=j;
            }
        }
        for(j=0; j<n; j++)
        {
            printf("%d ",a[hang][j]);
        }
        printf("\n");
        min=v[hang];//此次循环求出的最小值
    }
    return 0;
}
