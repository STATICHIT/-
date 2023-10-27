#include<stdio.h>
int jiecheng(int n)
{
    int ans;
    if(n==0||n==1)
        ans=1;
   if(n>1)
    ans=jiecheng(n-1)*n;
    return ans;
}
int main()
{
    int i,ans;
    unsigned t,n,m;
    scanf("%u",&t);
    for(i=0;i<t;i++)
    {
        scanf("%u %u",&n,&m);
        ans=jiecheng(m)/(jiecheng(n)*jiecheng(m-n));
        printf("%d\n",ans);
    }
    return 0;
}
