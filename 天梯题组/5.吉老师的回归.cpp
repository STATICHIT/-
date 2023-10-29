#include<bits/stdc++.h>
using namespace std;
string ss;
int n,s;
int main()
{
    cin>>n>>s;
    getchar();
    while(n--)
    {
        getline(cin,ss);
        if(ss.find("easy") != -1||ss.find("qiandao") != -1)
            continue;
        else
            s--;
        if(s<0)break;
    }
    if(s<0)cout<<ss;
    else cout<<"Wo AK le";
    return 0;
}

