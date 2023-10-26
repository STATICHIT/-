#include<stdio.h>
#include<string.h>
void main()
{
    char a[1000],b[1000];
    int alen,blen,i;
    gets(a);
    gets(b);
    alen=strlen(a);blen=strlen(b);
    for(i=0;i<alen&&i<blen;i++)
    {
        printf("%c%c",a[i],b[i]);
    }
    if(a>b)
    {
        for(;i<alen;i++)
           {
            printf("%c",a[i]);
           }
           printf("\n");
    }
    if(a<b)
    {
        for(;i<blen;i++)
           {
            printf("%c",b[i]);
           }
           printf("\n");
    }

}
///今天学会了大数之后明白这道题怎么写了！
///运用了相同长度部分相应处理后大者接尾的思想
