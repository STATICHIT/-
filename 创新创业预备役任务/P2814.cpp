#include<bits/stdc++.h>
using namespace std;
map<string,string> f;
string s,sf;
string getf(string i)
{
    if(i==f[i])return i;
    else return f[i]=getf(f[i]);
}
int main()
{
    char c;
    cin>>c;//接收第一个字符
    while(c!='$')
    {
        cin>>s;
        if(c=='#')//描述父亲
        {
            sf=s;//记录父亲名字
            if(f[s]=="")f[s]=s;//如果他还没有父亲，那么他是自己的祖宗
        }
        else if(c=='+') //描述儿子
        {
            f[s]=sf;//他的父亲是上一个被记录的父亲名字
        }
        else if(c=='?')//提问？
        {
            cout<<s<<" "<<getf(s)<<endl;
        }
        cin>>c;//再次接收第一个字符
    }
    return 0;
}
