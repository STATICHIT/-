#include<stdio.h>
struct people
{
    int num;
    int time;
} a[1001],temp;
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i].time);
        a[i].num=i;
    }
    for(j=1;j<=n-1;j++)
    {
        for(i=1;i<=n-j;i++)//��ʼ���������ܲ��ԣ�Ȼ���Ұ�i<=n-1-j�ĳ���i<=n-j�Ͷ���
        {
            if(a[i].time>a[i+1].time)
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    double sum=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            sum=sum+a[j].time;
        }
    }
    double aver=sum/n;
    for(i=1;i<=n;i++)
        printf("%d ",a[i].num);
    printf("\n");
    printf("%.2lf\n",aver);
    return 0;
}
