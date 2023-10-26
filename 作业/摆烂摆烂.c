#include<stdio.h>
#include<string.h>
char s[1000000+10];
int a[1000000+10];
int main()
{
    while(gets(s)!=NULL)
    {
        int len=strlen(s),k=1,g=0,i;
        for(i=len-1;i>=0;i--)//字符串转数字，个位放第一个，高位放后面
            a[k++]=s[i]-'0';
        for(i=1;i<=len;i++)
        {
            if(a[i]%2 == i%2)//按照规则转2进制
                a[i]=1;
            else
                a[i]=0;
        }
        long long int ans=0,v=1;
        for(i=1;i<=len;i++)
        {
            ans=(ans+a[i]*v)%1000000007;//这种地方都要边乘边取余哦
            v=v*2;
            v=v%1000000007;///关键：这里除一下以防位权数也超出限制
        }
        printf("%lld\n",ans);
    }
}
