#include<stdio.h>
int main()
{
    int t,n,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&k);
        for(i=1;i<k+1;i++)
        {
            if(a[i]<a[i-1])
            {
                j=i-1;
                int x=a[i];
                while(j>=0&&x<a[j])
                {
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1]=x;
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
