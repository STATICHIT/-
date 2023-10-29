#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],aa[100];
    scanf("%s",a);
    scanf("%s",aa);
    int n=strlen(a);
    if(n==0)
    {
        if(a[0]==aa[0])
            printf("OK");
        else
            printf("WRONG_ANSWER");
        return 0;
    }
    for(int j=0; j<n-1; j++)
    {
        for(int i=0; i<n-1-j; i++)
        {
            if(a[i]>a[i+1])
            {
                char t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    if(a[0]=='0')
    {
        for(int i=0; i<n; i++)
        {
            if(a[i]!='0')
            {
                char  t=a[i];
                a[i]=a[0];
                a[0]=t;
                break;
            }
        }
    }
    //printf(a);
    if(strcmp(a,aa)==0)
        printf("OK");
    else
        printf("WRONG_ANSWER");
    return 0;
}
