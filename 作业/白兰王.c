#include<stdio.h>
char a[100005];
int main()
{
    int n,i,b=0;
    scanf("%d",&n);
    getchar();
    gets(a);
    for(i=0; i<n-10; i++)
    {
        if(a[i]=='2')
        b++;
    }
    if(b>(n-11)/2)
        printf("yyds");
    else
        printf("orz");
    return 0;
}
