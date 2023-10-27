//A.t了
/*
#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int main()
{
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        int a[200010];
        for(int i=1; i<=n; i++)cin>>a[i];
        for(int i=1; i<=n-1; i++){
            for(int j=i+1; j<=n; j++)
            {
                if(a[i]<i&&i<a[j]&&a[j]<j)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int t,n,a[30];
int main()
{
    //-64
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>n;
        for(int i=1; i<=30; i++)a[i]=0;
        string str;
        cin>>str;
        for(char c:str)
        {
            int q=c-64;
            if(a[q]>0)ans++;
            else if(a[q]==0)ans+=2;
            a[q]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int t,len;
string s,p,str,u,the,m;
int num,i,j,l1,l2,flag;
//compare:等于返回0，前者大，返回正数，前者小，返回负数
//append：拼接
//substr：提取子串
//to_string(a);int转string

//去掉前导0
string fun(string s)
{
    num=0;
    for(j=0; j<s.size(); j++)
    {
        if(s[j]!='0')
        {
            break;
        }
        else
        {
            num++;
        }
    }
    if(num>0)s.erase(0,num);
    return s;
}

//比较两个字符串大小
int fun2(string s1,string s2)
{
    flag=0;
    l1=s1.size(),l2=s2.size();
    if(l1>l2)
    {
        return 1;
    }
    else if(l1<l2)
    {
        return 0;
    }
    else
    {
        for(j=0; j<=l1; j++)
        {
            if(s1[j]-'0'>s2[j]-'0')
            {
                return 1;
            }else if(s1[j]-'0'<s2[j]-'0'){
                return 0;
            }
        }
    }
    return 0;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        m="0";
        len=s.size();
        if(len==2)
        {
            cout<<s[0]-'0'+s[1]-'0'<<endl;
            continue;
        }
        for(i=0; i<len-1; i++)
        {
            str="";
            u="";
            the="";
            int sum=s[i]-'0'+s[i+1]-'0';
            p=to_string(sum);
            str=s.substr(0,i).append(p);
            u=s.substr(i+2,len-i-2);
            str=str.append(u);
            //cout<<"$str2:"<<str<<endl;
            the=fun(str);
            //cout<<"==="<<the<<endl;
            //cout<<"xxx:"<<fun2(the,m)<<endl;
            if(fun2(the,m)==1)
            {
                m=the;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int t,len;
string s,m;
int num,i,j,l1,l2,flag,sum;
string fun(string ss)
{
    num=0;
    for(j=0; j<ss.size(); j++)
    {
        if(ss[j]!='0')
        {
            break;
        }
        else
        {
            num++;
        }
    }
    if(num>0)ss.erase(0,num);
    return ss;
}
int main()
{
    cin>>t;
    while(t--)
    {
        flag=0;
        cin>>s;
        m="0";
        len=s.size();
        if(len==2)
        {
            cout<<s[0]-'0'+s[1]-'0'<<endl;
            continue;
        }

        for(i=0; i<len-1; i++)
        {
            sum=s[i]-'0'+s[i+1]-'0';
            if(sum>=10)
            {
                flag=1;
                break;
            }
        }

        if(flag == 1)
        {
            for(i=len-1; i>=0; i--)
            {
                sum=s[i]-'0'+s[i-1]-'0';
                if(sum>=10)
                {
                    string p=to_string(sum);
                    string str=s.substr(0,i-1).append(p);
                    string u=s.substr(i+1,len-i);
                    str=str.append(u);
                    string the=fun(str);
                    m=the;
                    break;
                }
                else
                {
                    continue;
                }

            }
        }
        else if(flag == 0)
        {
            int sum=s[0]-'0'+s[1]-'0';
            string p=to_string(sum);
            string u=s.substr(2,len-2);
            string str=p.append(u);
            string the=fun(str);
            m=the;
        }
        cout<<m<<endl;
    }
    return 0;
}
