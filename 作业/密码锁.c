/*
#include<stdio.h>
#include<string.h>
int max(int x,int y)
{
    return(x>=y?x:y);
}
int main()
{
    int k,i,j;
    int ans=0;
    int s[5];//储存各个科目题数
    int a[25];//储存各个题目所用时间
    int t[5]= {0}; //储存每个科目作业总时间
    int f[5]= {0}; //储存每个科目的最优处理时间
    int dp[25][2000];
    for(k=1; k<=4; k++)
        scanf("%d",&s[k]);
    for(k=1; k<=4; k++)
    {
        memset(dp,0,sizeof(dp));
        for(i=1; i<=s[k]; i++)
        {
            scanf("%d",&a[i]);
            t[k]+=a[i];
        }

            //printf("%d\n",t[k]);//检查
            for(i=1; i<=s[k]; i++) //质量
            {
                for(j=1; j<=t[k]/2; j++) //总容量
                {
                    if(j<a[i])
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
                }
            }

            f[k]=t[k]-dp[s[k]][t[k]/2];
        //printf("本科目所用时间为%d\n",f[k]);
    }
    for(i=1; i<=4; i++)
        ans=ans+f[i];
    printf("%d",ans);
    return 0;
}
*/
#include<stdio.h>
#include<string.h>
int dp[1205][25],sum,k[4],a[25];
int max(int x,int y)
{
	if(x>=y)
	return x;
	else
	return y;
}
void fun(int v,int n)
{
	int i,j;
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=v;i++)
	    {
		    if(i>=a[j])
		    dp[j][i]=max(dp[j-1][i],dp[j-1][i-a[j]]+a[j]);
		    else
		    dp[j][i]=dp[j-1][i];
	    }
	}
}
int main()
{
	int t=0,i,j,b;
	for(i=0;i<4;i++)
	scanf("%d",&k[i]);
	for(j=0;j<4;j++)
	{
	     memset(dp,0,sizeof(dp));
		sum=0;
		for(i=1;i<=k[j];i++)
		{
			scanf("%d",&a[i]);
			sum=sum+a[i];
		}
		fun(sum/2,k[j]);
		t=t+sum-dp[k[j]][sum/2];
	}
	printf("%d",t);
	return 0;
}
