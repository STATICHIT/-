/*
#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,len;
    char a[1000];
    char result[1000];
    while(~scanf("%s",a))
    {
        //printf("%d",strlen(a));
        len=strlen(a);
        if(len%2==0)//偶数个字符
        {
            for(i=0,j=len/2-1;i<len/2;j--)
            {result[i]=a[j];i++;}
            //printf("%d",i);
            for(j=len-1;i<len;j--,i++)
            {result[i]=a[j];}
            result[i]='\n';//要加结尾符号避免影响下一次输入
           for(j=0;j<i;j++)
         {
             printf("%c",result[j]);
         }
            printf("\n");
        }
        if(len%2!=0)//奇数个字符
        {
         for(i=0,j=(len-1)/2-1;i<(len-1)/2;j--)
         {
             result[i]=a[j];
             i++;
         }
         result[i]=a[i];
         for(i=i+1,j=len-1;i<len;j--)
         {
             result[i]=a[j];
             i++;
         }
         result[i]='\0';//要加结尾符号避免影响下一次输入
         for(j=0;j<i;j++)
         {
             printf("%c",result[j]);
         }
         printf("\n");
        }

    }
}
*/
#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char a[1001],r[1001];
    while(gets(a)!=NULL)
    {
        int j=0;
        for(i=strlen(a)-1; i>=0; i--)
        {
            r[j++]=a[i];
        }
        r[j]='\0';
        printf(r);
        printf("\n");
    }
    return 0;
}
