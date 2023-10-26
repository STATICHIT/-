#include<stdio.h>
void main()
{
    int n,k;//n为灯，k为人
    int sign[1005]= {0};
    //标志每盏灯的状态，初始时灯全部关闭，所以sign[i]=0；
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; i++) //依次判断每盏灯
    {
        for(j=1; j<=k; j++) //执行每个人对每盏灯的操作
        {
            if(i%j==0)
            {
                if(sign[i]==0)
                    sign[i]=1;
                else
                    sign[i]=0;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(sign[i]==1)
            printf("%d ",i);
    }
    printf("\n");
}
