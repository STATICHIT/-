//当字符串长度大于1时，若第一个字符与最后一个字符相同，则输出0；
//不相同则输出1，将最后一个字符改变，然后输出改变后的字符串。
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
