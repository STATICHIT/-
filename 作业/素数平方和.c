#include<stdio.h>
void main()
{
    int  n,m,i,j,sum=0;
    scanf("%d %d",&n,&m);
    if(n<=m)
    {
        for(i=n; i<=m; i++)
        {
            for(j=2; j<=i; j++)

            {
                if(i%j==0)
                    break;
            }
            if(j==i)
                sum=sum+i*i;
        }

        printf("%d\n",sum);
    }
}
