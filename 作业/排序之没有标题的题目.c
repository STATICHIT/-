#include<stdio.h>
#include<string.h>
int main()
{
    char m[20];
    int a[20],i,j,t;
    gets(m);
    int l=strlen(m);
    for(i=0; i<l; i++)
    {
        a[i]=m[i]-'0';
    }
    for(i=0;i<l-1;i++)//Ñ¡ÔñÅÅÐò·¨
    {
        for(j=i+1;j<l;j++)
        {
            if(a[j]<a[i])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }

    for(i=0;i<l;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
