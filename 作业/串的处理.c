///有三个地方需要注意
//考虑数字在第一个
//考虑空格在第一个
//考虑小写字母改变了之后下划线的判断
#include<stdio.h>
#include<string.h>
void main()
{
    int i,j;
    char a[300];
    while(gets(a)!=NULL)
    {
        //printf(a);//检查字符入录情况
        int alen=strlen(a);
        for(i=0; i<alen; i++)
        {
            if(a[0]>='a'&&a[0]<='z')
                a[0]-=32;//处理首字母
            //printf("%c",a[0]);//检查首字母改变情况
            else if(a[i-1]==' '&&a[i]>='a'&&a[i]<='z')
            {
                a[i]-=32;//每个单词第一个字母大写
            }
            else if(a[i]==' '&&a[i+1]==' ')
            {
                //不会的地方：删除多余空格
                a[i]='$';
            }

            else if(a[i]>='0'&&a[i]<='9'&&a[i-1]>='a'&&a[i-1]<='z'||a[i]>='0'&&a[i]<='9'&&a[i-1]>='A'&&a[i-1]<='Z')
            {
                for(j=0; j<alen-i; j++)
                    a[alen-j]=a[alen-1-j];
                alen+=1;
                a[i]='_';
            }
            else if(a[i]>='0'&&a[i]<='9'&&a[i+1]>='a'&&a[i+1]<='z'||a[i]>='0'&&a[i]<='9'&&a[i+1]>='A'&&a[i+1]<='Z')
            {
                for(j=0; j<alen-i; j++)
                    a[alen-j]=a[alen-1-j];
                alen+=1;
                a[i+1]='_';
            }
        }
        for(i=0; i<alen; i++)
        {
            if(a[i] == '$')
                continue;
            else
                printf("%c",a[i]);
        }
        printf("\n");
    }
}
