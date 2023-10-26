#include<stdio.h>
void main()
{
    int m,n,i,j,s;
    char a[105];
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {s=0;
        for(j=0; j<m; j++)
        {
            scanf("%c",&a[i]);
            getchar();
        }
        for(i=0; i<m; i++)
        {
            if(a[i]=='B')
                s=s+1;
        }
        printf("%d\n",s);
    }
}
