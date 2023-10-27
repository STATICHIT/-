#include<stdio.h>
#include<string.h>
int main()
{
    int a[2000],b[2000],i,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    int len=n>m?n:m;
    for(i=0;i<len;i++)
    {
        if(a[i]>b[i])
            m--;
    }
    printf("%d\n",m);
    return 0;
}
