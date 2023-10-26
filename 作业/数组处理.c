#include<stdio.h>
int main()
{
    int a[2][5],i,j,aver1,aver2,aver3,sum1=0,sum2=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
       sum1+=a[0][i];
    }
    aver1=sum1/5;
    for(i=0;i<5;i++)
    {
       sum2+=a[1][i];
    }
    aver2=sum2/5;
    aver3=(sum1+sum2)/10;
    int max=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<5;j++)
        {
          if(max<a[i][j])
                max=a[i][j];
        }
    }
    printf("%d %d %d %d\n",aver1,aver2,aver3,max);

    return 0;
}
