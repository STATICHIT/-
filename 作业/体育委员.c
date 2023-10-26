#include<stdio.h>
void main()
{
    int n,m,i,j,k;
    char a[105];
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%s",a);///输入字符串的正确方法
        k=0;
        for(j=0; j<m; j++)
        {
            if(a[j]=='B')
                k++;
        }
        printf("%d\n",k);
    }
}
