/*
#include<stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][6],sum[n];
    for(i=0;i<n;i++)//³õÊ¼»¯sum[]
        sum[i]=0;
    for(i=0;i<n;i++)
    {
        for(int k=0;k<5;k++)
            scanf("%d",&a[i][k]);
        for(j=0;j<5;j++)
            sum[i]+=a[i][j];
        //printf("sum[%d]=%d\n",i,sum[i]);//¼ì²é
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(a[i][1]>a[j][1]&&i!=j)
        {
            for(int k=0;k<5;k++)
            printf("%d ",a[i][k]);
            sum[i]=0;
            printf("\n");
        }
        else if(a[i][1] == a[j][1])
        {
            if(sum[i]>sum[j])
                for(int k=0;k<5;k++)
            printf("%d ",a[i][k]);
            printf("\n");
            else
               {for(int k=0;k<5;k++)
            printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
*/
///学了结构体之后发现这道题太简单啦！
#include<stdio.h>
struct fruit
{
    int a;
    int b;
    int c;
    int d;
    int e;
}tu[15];
int main()
{
    int i,j,n,sum[15]={0};
    struct fruit temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      {
        scanf("%d %d %d %d %d",&tu[i].a,&tu[i].b,&tu[i].c,&tu[i].d,&tu[i].e);
        sum[i]=tu[i].a+tu[i].b+tu[i].c+tu[i].d+tu[i].e;
      }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(tu[i].b<tu[j].b)
            {
                temp=tu[i];tu[i]=tu[j];tu[j]=temp;
            }
            else if(tu[i].b == tu[j].b)
            {
                if(sum[i]>sum[j])
                {
                    temp=tu[i];tu[i]=tu[j];tu[j]=temp;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d %d %d %d %d\n",tu[i].a,tu[i].b,tu[i].c,tu[i].d,tu[i].e);
    }
    return 0;
}
