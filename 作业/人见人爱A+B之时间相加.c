#include<stdio.h>
int main()
{
    int a[7],b[4],i,n;
    scanf("%d",&n);
    for(int j=0; j<n; j++)
    {
        for(i=0; i<6; i++)
        {
            scanf("%d",&a[i]);
        }
        b[2]=(a[2]+a[5])%60;
        int temp=(a[2]+a[5])/60;
        b[1]=((a[1]+a[4])+temp)%60;
        temp=((a[1]+a[4])+temp)/60;
        b[0]=a[0]+a[3]+temp;
        for(i=0; i<3; i++)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    return 0;
}
