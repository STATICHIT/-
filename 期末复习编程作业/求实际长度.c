#include<stdio.h>
void fun(char * std)
{
    int sum;
    while(std!='\0')
    {
        sum++;
        std++;
    }
    printf("�ַ���s�ĳ���Ϊ%d\n",sum);
}
int main()
{
	char s[100];
	gets(s);
	fun(s);
	return 0;
}
