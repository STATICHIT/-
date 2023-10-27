#include<stdio.h>
int min(int x, int y)
{
    return(x>y?y:x);
}
int main()
{
    int t,x,n,k,i,j,a[30],sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
       for(j=0;j<n-1;j++)
       for(i=0;i<n-1-j;i++)
           if(a[i]>a[i+1])
           {x=a[i];a[i]=a[i+1];a[i+1]=x;}
    }
    for(i=0;i<n;i++)
    {
        sum=a
    }

    return 0;
}
