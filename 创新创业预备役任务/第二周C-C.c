///C与D类似
#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char s[140],S[140];
        int i,len,top=0;
        gets(s);
        len=strlen(s);
        for(i=0; i<len; i++)
        {
            if(s[i] == '(')
            {
                S[top]='(';
                top++;
            }
            else if(s[i] == '[')
            {
                S[top]='[';
                top++;
            }
            else if(s[i] == ')')
            {

                if(S[top-1] == '(')
                    top--;
                else
                {
                    S[top]=')';
                    top++;
                }
            }
            else if(s[i] == ']')
            {
                if(S[top-1] == '[')
                    top--;
                else
                {
                    S[top]=']';
                    top++;
                }
            }
        }
        //printf("top=%d\n",top);

        if(top>0)
            printf("No\n");
        else if(top == 0)
            printf("Yes\n");

    }
    return 0;
}

///呜呜呜感动中国，改了起码50次！！终于做对啦太开心了
