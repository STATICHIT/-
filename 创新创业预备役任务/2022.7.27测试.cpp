/*
//1
#include<bits/stdc++.h>
using namespace std;
int t;
map<string,int> m;
string s;
int main()
{
    cin>>t;
    while(t--){
        cin>>s;
        if(m[s]==0){
            cout<<s<<endl;
            m[s]++;
        }
        else{
            cout<<s<<"("<<m[s]<<")"<<endl;
            m[s]++;
        }
    }
    return 0;
}
*/
/*
//3
#include<bits/stdc++.h>
using namespace std;
int t;
char m[1100][1100];
int main()
{
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        for(int j=1; j<=t; j++)
        {
            cin>>m[i][j];
        }
    }
    for(int i=1; i<=t; i++)
    {
        for(int j=i+1; j<=t; j++)
        {
            if(m[i][j]=='W')
            {
                if(m[j][i]!='L')
                {
                    cout<<"incorrect";
                    return 0;
                }
            }
            else if(m[i][j]=='L')
            {
                if(m[j][i]!='W')
                {
                    cout<<"incorrect";
                    return 0;
                }
            }
            else if(m[i][j]=='D')
            {
                if(m[j][i]!='D')
                {
                    cout<<"incorrect";
                    return 0;
                }
            }
        }
    }
    cout<<"correct";
    return 0;
}
*/
/*
//4
#include<bits/stdc++.h>
using namespace std;
int t,len,sum,flag;
string s,summ;
int main()
{
    cin>>t;
    while(t--)
    {
        flag=1;
        cin>>s;
        len=s.size();
        for(int i=len-1; i>0; i--)
        {
            sum=s[i]-'0'+s[i-1]-'0';
            if(sum>=10)
            {
                summ=to_string(sum);
                cout<<s.replace(i-1,2,summ)<<endl;
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            sum=s[0]-'0'+s[1]-'0';
            summ=to_string(sum);
            cout<<s.replace(0,2,summ)<<endl;
        }
    }
    return 0;
}
*/

/*
//8
#include<bits/stdc++.h>
using namespace std;
long long n,cnt1,cnt2;
long long a[1100],b[1100];
map<string,int>m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
        for(int i=1;i<=n;i++){
        cin>>b[i];
        m[to_string(b[i])]=1;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==b[i])cnt1++;
        if(m[to_string(a[i])]==1)cnt2++;
    }
    cout<<cnt1<<endl<<cnt2-cnt1<<endl;
    return 0;
}
*/

/*
//2
//情况很难 比较难写
#include<bits/stdc++.h>
using namespace std;
long long t,hc,dc,hm,dm,k,w,a;
int main()
{
    cin>>t;
    while(t--){
        cin>>hc>>dc>>hm>>dm>>k>>w>>a;

    }
    return 0;
}
*/


//6
#include<bits/stdc++.h>
using namespace std;
int t,n,k;
string s,ans,res;
char cur;
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>s;
        k=0;ans=s[0];cur=s[0];
        if(n==1)ans+=s[0];
        else{
            if(n>26){
                s=s.substr(0,26);
                n=26;
            }
            for(int i=1; i<n; i++){
                if(cur>s[i]){
                    ans+=s[i];
                    cur=s[i];
                }
                else{
                    k=i;
                    break;
                }
                k=i+1;
            }
            for(int i=k-1; i>=0; i--)ans+=s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
