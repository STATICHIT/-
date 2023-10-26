#include<stdio.h>
void main()
{
    int a[25];
    int i,n;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n-1; i++)
    {
        if(a[i]>a[i+1])
            break;
    }
    if(i==n-1)
        printf("YES\n");
    if(i!=n-1)
        printf("NO\n");

}

