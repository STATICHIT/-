#include<stdio.h>
int main()
{
    int n,i,j;
    while(~scanf("%d",&n))
    {
        int a[n][n];
        a[0][0]=1;
        for(i=0; i<n; i++)
        {
            if(i>0)
            {
                a[i][0]=a[i-1][0]+i;
            }
            for(j=1; j<n; j++)
            {
                if(j>=n-i)
                {
                    a[i][j]=-1;
                    continue;
                }
                a[i][j]=a[i][j-1]+i+j+1;
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i][j]==-1)
                {
                    printf(" ");
                    continue;
                }
                printf("%d ",a[i][j]);
            }
                printf("\n");//二维数组也要手动换行哦
        }
    }
    return 0;
}
