#include<stdio.h>
int max(int x,int y)
{
    return(x>=y?x:y);
}
int main()
{
    int y,w,m,d,ans=6;
    scanf("%d %d",&y,&w);
    m=max(y,w);
    d=6-m+1;
    for(int i=d;i>1;i--)
    {
        if(ans%i==0&&d%i==0)
        {
            d=d/i;
            ans=ans/i;
            break;
        }
    }
    printf("%d/%d",d,ans);
    return 0;
}
