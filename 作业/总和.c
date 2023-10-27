/*#include<stdio.h>
void main()
{
    int n,k,i,sum=0;
    int a[100005];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<=n-k;i++){
        for(int j=i;j<i+k;j++)
        {sum=sum+a[j];}
    }
    printf("%d\n",sum);
}
*/


#include<stdio.h>
void main()
{
    int n,k,i;
    int a[100005];
    scanf("%d %d",&n,&k);
    int sum[n+1];
    sum[0]=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i-1];
        //即把当前位和之前的和相加等于现在位置的和
    }
    long int s=0;//结果的范围用long定义
    for(int i=k;i<=n;i++)
    {
        int b=sum[i]-sum[i-k];
        s=s+b;
    }
    printf("%ld\n",s);
}
