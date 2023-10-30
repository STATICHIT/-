/*
#include<bits/stdc++.h>
using namespace std;

int n;
char word[110000][100];
char s[110000];
int nextt[110000];

void get_next(char *s,int len)
{
    int j,k;
    j=0;k=-1;
    nextt[0]=-1;
    while(j<len)
    {
        if(k == -1||s[j] == s[k])
        {
            ++k;
            ++j;
            nextt[j]=k;
        }
        else
            k=nextt[k];
    }
}
int KMP(char *s1,int l1,char *s2,int l2)
{
   get_next(s2,l2);
    int i,j;
    i=0;
    j=0;
    while(i<l1)//主串匹配完，此时子串的匹配长度就是我们要求的长度值，也就是j，所以返回j
    {
        if(j == -1 ||s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            j=nextt[j];
    }
    return j;
}
int main()
{
    cin>>n;
    cin>>s;
    int len=strlen(s);
    for(int i=1;i<n;i++)
    {
        cin>>word[i];
    }
    for(int i=1;i<n;i++)
    {
        int ll=strlen(word[i]);
        int m=KMP(s,len,word[i],ll);
        strcat(s,word[i]+m);//把与前面不包括公共部分的后半段连接到字符串s后
        len=len+ll-m;
    }
    cout<<s;
    return 0;
}
*/
/*
//总是有一个测试点过不了
#include<bits/stdc++.h>
using namespace std;

int n,la,lb;
string a,b;
int nextt[1100000];

void get_next(string s,int len)
{
    int j,k;
    j=0;k=-1;
    nextt[0]=-1;
    while(j<len)
    {
        if(k == -1||s[j] == s[k])
        {
            ++k;
            ++j;
            nextt[j]=k;
        }
        else
            k=nextt[k];
    }
}
int KMP(int pos)
{
   get_next(b,lb);
    int i,j;
    i=pos;//主串从pos处开始匹配
    j=0;
    while(i<la)//主串匹配完，此时子串的匹配长度就是我们要求的长度值，也就是j，所以返回j
    {
        if(j == -1 ||a[i] == b[j])
        {
            ++i;
            ++j;
        }
        else
            j=nextt[j];
    }
    return j;
}
int main()
{
    cin>>n>>a;
    la=a.size();
    n=n-1;
    while(n--)
    {
        cin>>b;
        lb=b.size();
        int pos=KMP(max(0,la-lb));//如果前串长则只需要从后串长度后缀处开始匹配，否则从0开始
        //cout<<"pos="<<pos<<endl;
        a+=b.substr(pos,lb);
        //cout<<a<<endl;
        la+=lb-pos;
    }
    cout<<a;
    return 0;
}
*/
//把上面这个string类处改成char字符串数组就过了
#include<bits/stdc++.h>
using namespace std;

int n,la,lb;
char a[1100000],b[1100000];
int nextt[1100000];

void get_next(char *s,int len)
{
    int j,k;
    j=0;k=-1;
    nextt[0]=-1;
    while(j<len)
    {
        if(k == -1||s[j] == s[k])
        {
            ++k;
            ++j;
            nextt[j]=k;
        }
        else
            k=nextt[k];
    }
}
int KMP(int pos)
{
   get_next(b,lb);
    int i,j;
    i=pos;//主串从pos处开始匹配
    j=0;
    while(i<la)//主串匹配完，此时子串的匹配长度就是我们要求的长度值，也就是j，所以返回j
    {
        if(j == -1 ||a[i] == b[j])
        {
            ++i;
            ++j;
        }
        else
            j=nextt[j];
    }
    return j;
}
int main()
{
    cin>>n>>a;
    la=strlen(a);
    n=n-1;
    while(n--)
    {
        cin>>b;
        lb=strlen(b);
        int pos=KMP(max(0,la-lb));//如果前串长则只需要从后串长度后缀处开始匹配，否则从0开始
        for(int j=pos;j<lb;j++)
            a[la++]=b[j];
    }
    cout<<a;
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int n,la,lb;
#define M 1100000
char a[M],b[M];
int nextt[M];

void get_next(char *s,int len)
{
    int j,k;
    j=0;
    k=-1;
    nextt[0]=-1;
    while(j<len)
    {
        if(k == -1||s[j] == s[k])
        {
            ++k;
            ++j;
            nextt[j]=k;
        }
        else
            k=nextt[k];
    }
}
int kmp(int pos)
{
    get_next(b,lb);
    int i=pos;
    int j=0;
    while(i<la)
    {
        if(j==-1||a[i]==b[j])
        {
            ++i;
            ++j;
        }
        else
            j=nextt[j];
        if(j==lb)
            return lb;
    }
    return j;
}
int main()
{
    cin>>n>>a;
    la=strlen(a);
    int i,j;
    for(i=1; i<n; i++)
    {
        cin>>b;
        lb=strlen(b);
        int pos=kmp(max(0,la-lb));
        for(j=pos; j<lb; j++)
            a[la++] = b[j];
    }
    cout<<a;
    return 0;
}
*/
