#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int lnum;//未匹配左括号数
int ans;//节点数
int main()
{
    cin>>t;
    while(t--)
    {
        lnum=0;ans=0;//一定要记得多组输入计数器要清零！！
        cin>>n>>m;//n为括号串长度
        char s[n+1];
        cin>>s;//括号序列
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')//左括号计数器
                lnum++;
            else if(lnum!=0)//创建匹配括号序列
            {
                lnum--;
                ans++;
            }
        }
        if(ans>=m)//使得至少m个子序列为匹配括号串
            cout<<1;
        else
            cout<<0;
        if(t!=0)
            cout<<endl;
        }
    return 0;
}
