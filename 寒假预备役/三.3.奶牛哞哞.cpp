
#include<bits/stdc++.h>
using namespace std;
char s1[100],s2[100];
int nextt[100];
int len1,len2,ans1,ans2;

void get_next(char str[],int len)//和模板kmp一模一样的操作
{
    int i=0,j=-1;
    nextt[0]=-1;
    while(i<len)
    {
        if(j == -1 ||str[i] == str[j])
        {
            ++i;
            ++j;
            nextt[i]=j;
        }
        else
        j=nextt[j];
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
    cin>>s1>>s2;
    len1=strlen(s1);
    len2=strlen(s2);
    //情况1：s1前缀，s2后缀
    ans1=KMP(s1,len1,s2,len2);
    //情况2：s2前缀，s1后缀
    ans2=KMP(s2,len2,s1,len1);
    cout<<max(ans1,ans2);
    return 0;
}
