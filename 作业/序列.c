//给你一个正整数Num，请输出所有连续的递增（+1）
//的正整数序列，使其之和等于Num，如不存在则输出NULL。
#include<stdio.h>
void main()
{
    int i,s=0,num,j,k;
    scanf("%d",&num);
    for(i=2;s<=num;i++)
    {
        s=s+i;
        if((num-s)%i==0)
        {
            k=(num-s)/i;
            for(j=1;j<=i;j++)
                printf("%d ",j+k);
            printf("\n");
        }
    }
}
