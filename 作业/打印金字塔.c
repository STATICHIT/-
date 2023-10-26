#include<stdio.h>
void main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=2*n-3; j++)
        printf(" ");
        for(j=1; j<=i; j++)
        {
            if(i==n||n==1)//最后一行第一个字母前无空格
                printf(" %d",j);
            else
                printf(" %d",j);
        }

        for(j=i-1; j>=1; j--)
            printf(" %d",j);
        printf("\n");
    }
}
