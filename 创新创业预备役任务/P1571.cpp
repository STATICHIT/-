#include<bits/stdc++.h>
using namespace std;
int n,m,o,k[100010];
map<long long,int> a,b;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>o;
        k[i]=o;//记录比赛1的编号
        a[o]=1;//记录存在者
    }
    for(int i=0;i<m;i++)
    {
     cin>>o;
     if(a[o]==1)//若存在过
            b[o]=1;//标记二次存在
    }
    for(int i=0;i<n;i++){
           if(b[k[i]]==1)//二次存在者按比赛一顺序输出
            cout<<k[i]<<" ";
    }
    return 0;
}
