#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,k=1,len[21],max,num;
    scanf("%d",&n);
    char s[21][110];
    for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]);
        len[k++]=strlen(s[i]);
    }
    /*for(i=1;i<=n;i++)
    {
        printf("%d\n",strlen(s[i]));
    }*///检查长度测量
    max=len[1],num=1;
    for(i=2;i<=k;i++)
    {
        if(max<len[i])
            {max=len[i];
             num=i;}
    }
    //printf("maxlen=%d\n",max);
    int sign=0,q=0,h[21];
    for(i=1;i<=k;i++)
    {
        if(len[i] == max)
            {h[q++]=i;
            sign++;}
    }
    /*for(i=0;i<q;i++)//检查h数组赋值及sign计算
    {
        printf("h[%d]==%d\n",i,h[i]);
    }
    printf("sign=%d\n",sign);*/
    if(sign == 1)
    {
        printf("%d\n%s\n",num,s[num]);
    }
    else if(sign > 1)
    {
        num=h[0];
        for(i=0;i<sign;i++)
        {
            if(strcmp(s[num],s[h[i]])<0)
            num=h[i];
        }
        printf("%d\n%s\n",num,s[num]);
    }
    return 0;
}
