#include<bits/stdc++.h>
using namespace std;

string s1,s2;
bool check(string s)
{
    int len=s.size();
    for(int i=0; i<len; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            continue;
        else
            return 0;
    }
    return 1;
}
int szint(string s)
{
    int len=s.size();
    int ans=0;
    for(int i=0; i<len; i++)
    {
        ans+=(s[i]-'0')*pow(10,len-i-1);
    }
    return ans;
}
int main()
{
    cin>>s1;
    getchar();//Çå³ý¿Õ¸ñ
    getline(cin,s2);
    int f1=0,f2=0;
    int a1,a2;
    if(check(s1))
    {
        f1=1;
        a1=szint(s1);
        if(a1>1000||a1<1)
            f1=0;
    }
    if(check(s2))
    {
        f2=1;
        a2=szint(s2);
        if(a2>1000||a2<1)
            f2=0;
    }
    if(f1==1 && f2==1)
    {
        cout<<a1<<" + "<<a2<<" = "<<a1+a2;
    }
    if(f1 == 1 && f2 == 0)
    {
        cout<<a1<<" + "<<"?"<<" = "<<"?";
    }
    if(f1 == 0 && f2 == 1)
    {
        cout<<"?"<<" + "<<a2<<" = "<<"?";
    }
    if(f1 == 0 && f2 == 0)
    {
        cout<<"?"<<" + "<<"?"<<" = "<<"?";
    }
    return 0;
}
