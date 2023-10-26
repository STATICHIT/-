#include<stdio.h>
void main()
{
    int a[11],m,n,i,j;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    getchar();//吸收回车键
    scanf("m:%d",&m);
    getchar();//吸收回车键
    scanf("n:%d",&n);
    /*for(i=0;i<10;i++)
    {printf("%d\n",a[i]);
        }
        printf("%d %d\n",m,n);*///检查输入是否正确
    for(i=0;i<m;i++)
    {
    printf("%d ",a[i]);
    }
    for(i=m+n-1;i>=m;i--)
    {
        printf("%d ",a[i]);
    }
    for(i=m+n;i<10;i++)
    {
        printf("%d ",a[i]);
    }
}
