#include<stdio.h>
#include<string.h>
char s[1000000+10];
int a[1000000+10];
int main()
{
    while(gets(s)!=NULL)
    {
        int len=strlen(s),k=1,g=0,i;
        for(i=len-1;i>=0;i--)//�ַ���ת���֣���λ�ŵ�һ������λ�ź���
            a[k++]=s[i]-'0';
        for(i=1;i<=len;i++)
        {
            if(a[i]%2 == i%2)//���չ���ת2����
                a[i]=1;
            else
                a[i]=0;
        }
        long long int ans=0,v=1;
        for(i=1;i<=len;i++)
        {
            ans=(ans+a[i]*v)%1000000007;//���ֵط���Ҫ�߳˱�ȡ��Ŷ
            v=v*2;
            v=v%1000000007;///�ؼ��������һ���Է�λȨ��Ҳ��������
        }
        printf("%lld\n",ans);
    }
}
