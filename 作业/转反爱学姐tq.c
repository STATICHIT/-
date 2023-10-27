#include<stdio.h>
#include<string.h>
void main()
{
    char a[105+1];
    gets(a);
    int n=strlen(a),i,j;
    a[n]=' ';//因为数组是从a[0]开始的所以此处a[n]就是指第n+1个数
    for(i=0; i<n+1; i++)
    {
        if(a[i]==' ')//遇到空格时倒叙输出
        {
            for(j=i-1; j>=0; j--)//j=i-1是要避开当前空格
            {//如果是首单词，前面没有空格 也可以通过j>=0的条件达到停止循环的目的
                if(a[j]==' ')
                {
                    break;//遇到该单词前的空格就结束
                }

                printf("%c",a[j]);
            }
            printf(" ");//倒叙之后记得把空格补上哦！
        }
    }
}
