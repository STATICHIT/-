//���ַ������ȴ���1ʱ������һ���ַ������һ���ַ���ͬ�������0��
//����ͬ�����1�������һ���ַ��ı䣬Ȼ������ı����ַ�����
#include<stdio.h>
#include<string.h>
int main()
{
    int n,len;
    scanf("%d",&n);
    char s[1000];
    while(n--)
    {
        scanf("%s",s);
        getchar();
        len=strlen(s);
        if(len <= 1)
            printf("0\n");
        else if(s[0] == s[len-1])
            printf("0\n");
        else if(s[0] != s[len-1])
        {
            printf("1\n");
            if(s[len-1] == 'a')
            {
                s[len-1]='b';
                printf("%s\n",s);
            }
            else if(s[len-1] == 'b')
            {
                s[len-1]='a';
                printf("%s\n",s);
            }
        }
    }
    return 0;
}
