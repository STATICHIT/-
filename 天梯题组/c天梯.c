#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        char str[10000];
        int top=0;
        char s[10000];
        gets(s);
        if(s==NULL)
        {printf("No\n");return 0;}
        for(int i=0; i<strlen(s);i++)
        {
            if(s[i]=='{')
            {
                top++;
                str[top]='{';
            }
            else if(s[i]=='¡¾')
            {
                top++;
                str[top]='¡¾';
            }
            else if(s[i]=='<')
            {
                top++;
                str[top]='<';
            }
            else if(s[i]=='(')
            {
                top++;
                str[top]='(';
            }
            else if(s[i]=='£¨')
            {
                top++;
                str[top]='£¨';
            }
            else if(s[i]=='[')
            {
                top++;
                str[top]='[';
            }
            else if(s[i]=='}')
            {
                if(str[top]=='{')
                    top--;
                else break;
            }
            else if(s[i]=='¡¿')
            {
                if(str[top]=='¡¾')
                    top--;
                else break;
            }
            else if(s[i]==')')
            {
                if(str[top]=='(')
                    top--;
                else break;
            }
            else if(s[i]=='£©')
            {
                if(str[top]=='£¨')
                    top--;
                else break;
            }
            else if(s[i]=='>')
            {
                if(str[top]=='<')
                    top--;
                else break;
            }
            else if(s[i]==']')
            {
                if(str[top]=='[')
                    top--;
                else break;
            }
        }
        //cout<<"top=="<<top<<endl;
        if(top==0)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
