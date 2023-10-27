///D与C类似
//把程序中的括号们提出来判断，不用管除括号外的字符
#include<stdio.h>
#include<string.h>
int main()
{
    int top=0,i,len;//注意，这里top记得要赋初值为0哦！
    char s[1000],S[1000];
    while(gets(s)！=NULL)//一行一行地输入并判断，每一行剩下的继续与下一行合并判断
    {
        len=strlen(s);

        char sign[]="Ctrl+Z";
        if(strcmp(sign,s) == 0)//当前程序判断结束条件
        {
            if(top>0)
                printf("Wrong\n");
            else if(top == 0)
                printf("Right\n");
            top=0;//清空栈
            //这里令栈顶为0即可清空栈，这样同时初始化了下一个程序判断要用的top，无需用memset
            continue;
        }

        for(i=0; i<len; i++)
        {
            if(s[i] == '(')
            {
                S[top]='(';
                top++;
            }
            else if(s[i] == '{')
            {
                S[top]='{';
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
            else if(s[i] == '}')
            {
                if(S[top-1] == '{')
                    top--;
                else
                {
                    S[top]='}';
                    top++;
                }
            }
        }
    }
    return 0;
}
