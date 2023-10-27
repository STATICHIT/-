
#include<stdio.h>
#include<string.h>
int main()
{
    char a[101],b[101];
    int i,j,k,flag;
    while(~scanf("%s",&a))
    {
        int m=0;//每次输入要重新将m归0
        memset(b,-7,101);//把b数组所有元素定义为-7(别的数也行）
        for(i=0; i<strlen(a); i++)//这一块双重循环加if嵌套是为了找出不重复的字符
        {
            for(j=0; j<strlen(a); j++)
            {
                if((a[i]==a[j])&&(i!=j))//如果不止出现一次就提出来！
                {
                    flag=1;
                    break;
                }
                else
                    flag=0;
            }
            if(flag==0)
            {
                b[m++]=a[i];///b[m]保存不重复的字符
            }
        }

        for(i=0; i<strlen(a); i++)//这个循环是要标记不重复的数为-1
        {
            for(j=0;j<m;j++)
            if(a[i]==b[j])
            {
                a[i]=-1;break;
            }
        }

        for(i=0; i<strlen(a); i++)
        {
            //怎么使不重复的字符不进入循环？
            if(a[i]==-1)
            {
                continue;//使不重复的字符以及已打印的字符（下面可以看到打印了就赋）不进入循环
            }
            else
            {
                printf("%c:%d",a[i],i);//打印第一个出现的字符(因为逗号所以第一个和后面的要分开打)
                for(j=i+1; j<strlen(a); j++)
                {
                    if(a[j]==a[i])
                    {
                        printf(",%c:%d",a[j],j);//打印后续同前面打印的字符相同的字符
                        a[j]=-1;//标记已打印的字符
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
