#include<stdio.h>
#include<string.h>//因为主函数中用到了strlen函数，所以要加入string.h头文件
void main()
{
    int i;
	char a[101];
	gets(a);
	for(i=strlen(a)-1;i>=0;i--)
        putchar(a[i]);//因为要反过来输出
                      //所以是一个一个字符输出
                      //所以用putchar而不用puts
}
