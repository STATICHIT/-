#include<stdio.h>
void fun(char * std)
{
    int sum;
    while(std!='\0')
    {
        sum++;
        std++;
    }
    printf("字符串s的长度为%d\n",sum);
}
int main()
{
	char s[100];
	gets(s);
	fun(s);
	return 0;
}
