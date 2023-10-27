#include <stdio.h>
int main()
{
    int n,m,i,j,k,t,a[1000];
    scanf("%d",&n);
    for(k=0; k<n; k++)
    {
        scanf("%d",&m);
        for(i=0; i<m; i++)
            scanf("%d",&a[i]);
        for(i=1; i<=m; i++)
        {
            for(j=0; j<(m-i); j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }
        for(i=0; i<m; i++)
        {
            if(i==m-1)
                printf("%d",a[i]);
            else
                printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
