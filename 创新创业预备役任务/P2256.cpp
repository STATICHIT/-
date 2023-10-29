#include <bits/stdc++.h>
using namespace std;
int n,m,mmf[20001];
map<string,int> name;
string s,ss;

int getf(int i)
{
    if(f[i]==i)return i;
    else return f[i]=getf(f[i]);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)f[i]=i;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        name[s]=i;//按顺序编号，名字和序号map映射
    }
    for(int i=1; i<=m; i++)//合并
    {
        cin>>s>>ss;
        f[getf(name[s])]=getf(name[ss]);
    }
    cin>>mm;
    while(mm--)
    {
        cin>>s>>ss;
        if(getf(name[s])==getf(name[ss]))cout<<"Yes.";
        else cout<<"No.";
        if(mm!=0)cout<<endl;

    }
    return 0;
}
