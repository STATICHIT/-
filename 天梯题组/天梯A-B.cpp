/*
//codeblock上没问题，但过不了测试
///PTA中c可以用gets（），c++不支持
#include<bits/stdc++.h>//pta中c++好像不让用gets
using namespace std;
#include<map>
char s1[10001],s2[10001];
map<char,int>a;
int main()
{
    gets(s1);//gets可以接受带空格的字符串，以回车为结束标志
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

//通过代码
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
    getline(cin,s1);//getline用于string类，可用于输入一行带空格的字符串
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
