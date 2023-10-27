#include<stdio.h>
void main()
{
    int n,i,j;
    int a[100];
    while(~scanf("%d",&n))
    {
        int g[21]= {0};
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0; i<n; i++)
        {
            for(j=1; j<=20; j++)
            {
                if(a[i]==j)
                {
                    g[j]+=1;
                    break;
                }
                else
                    continue;
            }
        }
        for(j=1; j<=20; j++)
        {
            printf("%d:%d\n",j,g[j]);
        }
    }
}
