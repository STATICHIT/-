#include<stdio.h>
void main()
{
    int a[2][5];
    int b[2][5];
    int i,j,s;
    for(i=0; i<2; i++)
    {
        for(j=0; j<5; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0; i<2; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<2; i++)
    {
        for(j=0; j<5; j++)
        {
            b[i][j]=2*a[i][j];
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}
