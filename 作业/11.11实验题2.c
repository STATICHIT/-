///编程找到10到100间因子个数最多的数，输出其因子个数。
#include<stdio.h>
#include<math.h>
void main()
{
    int i,j;
    int time[100];
    for(i=10;i<=100;i++)
    {
        time[i]=2;
    }
    for(i=10;i<=100;i++)
    {
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                time[i]+=2;
        }
    }
    int max;
    time[max]=time[10];
    for(i=10;i<=100;i++)
    {
        if(time[max]<time[i])
        {
            max=i;
        }
    }
    printf("10到100中因子数最多的为%d，它的因子数为%d。\n",max,time[max]);

}
