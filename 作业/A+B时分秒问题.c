#include<stdio.h>
#include<string.h>//��Ϊ���������õ���strlen����������Ҫ����string.hͷ�ļ�
void main()
{
    int i;
	char a[101];
	gets(a);
	for(i=strlen(a)-1;i>=0;i--)
        putchar(a[i]);//��ΪҪ���������
                      //������һ��һ���ַ����
                      //������putchar������puts
}
