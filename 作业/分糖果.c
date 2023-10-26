#include<stdio.h>
long long int a[200000+10];
int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        int x=0,y=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            {scanf("%d",&a[i]);
            if(a[i] == 0)
                x++;
            else if(a[i] == 1)
                y++;
            }
        //printf("x=%d y=%d\n",x,y);//检查x，y个数统计
        int ans=y;
        for(i=1;i<=x;i++)
        {
            ans=(ans*2)%1000000007;//每乘一次都要取模，因为过程中ans可能超范围
        }
        printf("%lld\n",ans);
    }
    return 0;
}
