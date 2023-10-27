#include<stdio.h>
int main()
{
    int i,n;
    int f[11]={0,1,2};
    for(i=3;i<=10;i++)
        f[i]=f[i-1]+f[i-2];
    while(~scanf("%d",&n))
    {
        printf("%d\n",f[n]);
    }
    return 0;
}
