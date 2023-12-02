#include<stdio.h>
int a[1000001],b[100001];
int fun(int * a,int n,int b)
{
    int mid,left=0,right=n-1,sign=-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(b == a[mid])
        {
            sign=mid;
            right=mid-1;
        }
        else if(b<a[mid])
        {
            right=mid-1;
        }
        else if(b>a[mid])
        {
            left=mid+1;
        }
    }
    if(sign!=-1)
       return(sign+1);
    if(left>right)
        return(-1);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<m;i++)
        printf("%d ",fun(a,n,b[i]));
    return 0;
}
