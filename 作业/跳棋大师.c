#include<stdio.h>
int main()
{
    int n,i,a[100005]= {0,1,0,1};
    while(~scanf("%d",&n))
    {
        for(i=4; i<=n; i++)
        {
            a[i]=(a[i-1]+a[i-2]+1)%1000000007;
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
