/*
//codeblock��û���⣬�������˲���
///PTA��c������gets������c++��֧��
#include<bits/stdc++.h>//pta��c++��������gets
using namespace std;
#include<map>
char s1[10001],s2[10001];
map<char,int>a;
int main()
{
    gets(s1);//gets���Խ��ܴ��ո���ַ������Իس�Ϊ������־
    gets(s2);
    for(int i=0; i<strlen(s2); i++)
        a[s2[i]]=1;
    for(int i=0; i<strlen(s1); i++)
    {
        if(s1[i]==' ')
            cout<<" ";
        else if(a.count(s1[i])==0)
            cout<<s1[i];
        else
            continue;
    }
    cout<<endl;
    return 0;
}

//ͨ������
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100000],b[100000];
	gets(a);
	gets(b);
	for(int i=0;i<strlen(a);i++)
	{
		if(strchr(b,a[i]))
			continue;
		else
			printf("%c",a[i]);
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
#include<map>
map<char,int>a;
int main()
{
    string s1,s2;
    getline(cin,s1);//getline����string�࣬����������һ�д��ո���ַ���
    getline(cin,s2);
    for(int i=0; i<s2.length(); i++)
        a[s2[i]]=1;
    for(int i=0; i<s1.length(); i++)
    {
        if(s1[i]==' ')
            cout<<" ";
        else if(a.count(s1[i])==0)
            cout<<s1[i];
        else
            continue;
    }
    return 0;
}
