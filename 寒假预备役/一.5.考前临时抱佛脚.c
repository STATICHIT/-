//本质：0/1背包问题
///把总时间的一半当作背包容量
///每个题的时间当成物体的质量
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
    int dp[25][2000];///tip：dp表最大宽度为20*60（想想为什么）
    for(k=1; k<=4; k++)
        scanf("%d",&s[k]);
    for(k=1; k<=4; k++)
    {
        memset(dp,0,sizeof(dp));//每操作一门科目要重新初始化dp表哦
        for(i=1; i<=s[k]; i++)///tip
        {
            scanf("%d",&a[i]);
            t[k]+=a[i];
        }

            //printf("%d\n",t[k]);//检查
            for(i=1; i<=s[k]; i++) //质量
            {
                for(j=1; j<=t[k]/2; j++) //总容量
                {
                    if(j<a[i])///tip（抽象：是判断能否装下当前物品）
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
                }
            }

            f[k]=t[k]-dp[s[k]][t[k]/2];//当前科目的最短时间为总时间减去dp时间
        //printf("本科目所用时间为%d\n",f[k]);
    }
    for(i=1; i<=4; i++)
        ans=ans+f[i];//把每一科的最优时间相加即得到结果
    printf("%d",ans);
    return 0;
}



/*
#include<stdio.h>
int s1,s2,s3,s4,sum;
int a[21],b[21],c[21],d[21];
void sort(int * arr,int n)
{
    int i,j,t;
    for(j=0;j<n-1;j++)
    {
        for(i=0;i<n-1-j;i++)
        {
            if(*(arr+i)<*(arr+i+1))
            {
                t=*(arr+i);
                *(arr+i)=*(arr+i+1);
                *(arr+i+1)=t;
            }
        }
    }
}
//思路：排序后 两两绑定 依次算出每科最短时间
void time(int * arr,int n)
{
    if(n%2==0)
    {arr[n]=0;
    n=n+1;
    }
        for(int k=0;k<n;k=k+2)
        {
            sum=sum+arr[k];
        }
}
int main()
{
    int i;
    scanf("%d %d %d %d",&s1,&s2,&s3,&s4);

   for(i=0;i<s1;i++)
       scanf("%d",&a[i]);
    sort(a,s1);
    time(a,s1);

    //for(i=0;i<s1;i++)
    //printf("%d ",a[i]);
    //printf("\n");

    for(i=0;i<s2;i++)
       scanf("%d",&b[i]);
    sort(b,s2);
    time(b,s2);

    for(i=0;i<s3;i++)
       scanf("%d",&c[i]);
    sort(c,s3);
    time(c,s3);

    for(i=0;i<s4;i++)
       scanf("%d",&d[i]);
    sort(d,s4);
    time(d,s4);

    printf("%d",sum);
}
*/
