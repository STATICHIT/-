#include<stdio.h>
void main()
{
    int n,i;
    char a[101];
    char v;
    int m=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }
    getchar();
    for(i=2;i<n;i=i+2)
    {
        if(a[i]=='v'&&a[i-1]=='v'&&a[i-2]=='v')
            m+=1;
    }
    printf("%d",m);
}
