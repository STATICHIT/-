///D��C����
//�ѳ����е�������������жϣ����ùܳ���������ַ�
#include<stdio.h>
#include<string.h>
int main()
{
    int top=0,i,len;//ע�⣬����top�ǵ�Ҫ����ֵΪ0Ŷ��
    char s[1000],S[1000];
    while(gets(s)��=NULL)//һ��һ�е����벢�жϣ�ÿһ��ʣ�µļ�������һ�кϲ��ж�
    {
        len=strlen(s);

        char sign[]="Ctrl+Z";
        if(strcmp(sign,s) == 0)//��ǰ�����жϽ�������
        {
            if(top>0)
                printf("Wrong\n");
            else if(top == 0)
                printf("Right\n");
            top=0;//���ջ
            //������ջ��Ϊ0�������ջ������ͬʱ��ʼ������һ�������ж�Ҫ�õ�top��������memset
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
