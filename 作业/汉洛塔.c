#include<stdio.h>
#include<math.h>
void main()
{
    int n,i,ans;
    int a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ans=pow(2,a[i])-1;
        printf("%dÌì\n",ans);
    }
}
