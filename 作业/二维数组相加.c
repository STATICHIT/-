#include<stdio.h>
void main()
{
    int a[5];
    int b[5];
    int sum[5];
    int i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=0;i<5;i++)
    {
        sum[i]=a[i]+b[i];
    }
    for(i=0;i<5;i++)
    {
        printf("%d ",sum[i]);
    }
    printf("\n");
}
