//这道题利用的是桶排的思想
//有重合数据但只取一次就考虑一下桶排
#include<stdio.h>
int main()
{
    int i,j,L,M,x,y,a[10001]={0},time=0;
    scanf("%d %d",&L,&M);
    for(j=0;j<M;j++)
    {
        scanf("%d %d",&x,&y);
        for(i=x;i<=y;i++)
            a[i]=1;
    }
    for(i=0;i<=L;i++)
    {
        if(a[i] == 0)
            time++;
    }
    printf("%d\n",time);
    return 0;
}
