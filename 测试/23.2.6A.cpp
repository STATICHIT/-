/*
#include<bits/stdc++.h>
using namespace std;
int f[110],n,m,x,y;
//找爹
int getf(int i)
{
    return f[i]==i?i:f[i]=getf(f[i]);
}
//合并
void hebing(int x,int y)
{
    int xx=getf(x);
    int yy=getf(y);
    if(xx==yy)return;
    f[xx]=yy;
}
int main()
{
    //初始化
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        f[i]=i;
    }
    while(m--)
    {
        cin>>x>>y;
        hebing(x,y);
    }
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        if(i==getf(i))
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
int k,a,b,mxa,mni;
int main()
{
    cin>>k;
    while(k--)
    {
        cin>>a>>b;
        if(a>=b){
            for(int i=0;i<b;i++){
                cout<<"10";
            }
            for(int i=0;i<a-b;i++){
                cout<<"0";
            }
        }else{
            for(int i=0;i<a;i++){
                cout<<"10";
            }
            for(int i=0;i<b-a;i++){
                cout<<"1";
            }
        }
        cout<<endl;
    }
    return 0;
}
