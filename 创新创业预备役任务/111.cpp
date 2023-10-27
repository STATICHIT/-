//1.
/*
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str="";
    for(int i=0;i<n;i++)str+=".";
    string ss[5]={{"oooooooooooo"},
    {"..oo.o..o..o"},{"oooo.ooooooo"},
    {"o..o.oo..o.."},{"oooooooooooo"}};

    for(string s:ss){
        s.insert(3,str);
        s.insert(6+n,str);
        s.insert(9+2*n,str);
        cout<<s<<endl;
    }
    return 0;
}
*/
//2
/*
#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a%b==0){
            cout<<"0"<<endl;
        }else{
            int o=a/b;
            cout<<(o+1)*b-a<<endl;
        }
    }
    return 0;
}
*/
//3：佛洛依德法
/*
#include<iostream>
using namespace std;
int n,m,ss,tt;
int s,t,w;
int mmap[2510][6210]={};

int main()
{
    cin>>n>>m>>ss>>tt;
    int x=m;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            mmap[i][j]=1000000000;
    while(x--)
    {
        cin>>s>>t>>w;
        mmap[s][t]=w;
        mmap[t][s]=w;
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                mmap[i][j]=mmap[i][j]>mmap[i][k]+mmap[k][j]?mmap[i][k]+mmap[k][j]:mmap[i][j];
    cout<<mmap[ss][tt];
    return 0;
}
*/
/*
//迪杰斯特拉法
#include<iostream>
using namespace std;
int n,m,ss,tt;
int s,t,w,minn,u;
int mmap[2510][6210],dis[2510],book[2510]={0};

int main()
{
    cin>>n>>m>>ss>>tt;
             //要求的是ss到tt的最短路径，所以用迪杰斯特拉需以ss为起点
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j)mmap[i][j]=0;
        else mmap[i][j]=1000000000;

    while(m--)
    {
        cin>>s>>t>>w;
        mmap[s][t]=w;
        mmap[t][s]=w;
    }

    for(int i=1;i<=n;i++)dis[i]=mmap[ss][i];
    for(int i=1;i<=n-1;i++){
        minn=1000000000;
        for(int j=1;j<=n;j++){
            if(book[j]==0 &&dis[j]<minn){
                minn=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(int v=1;v<=n;v++){
            if(mmap[u][v]<1000000000){
                if(dis[v]>dis[u]+mmap[u][v])
                    dis[v]=dis[u]+mmap[u][v];
            }
        }

    }
    cout<<dis[tt];
    return 0;
}
*/

//4
/*
#include<iostream>
using namespace std;
int k,m,n;
string str;
int a,b,c;
int main()
{
    int cnt=0;
    cin>>k>>m;
    cin>>str;
    cin>>n;
    cnt=str.length();
    while(n--){
        cin>>a>>b>>c;
        str.insert(c,str.substr(a,b-a));
        cnt+=b-a;
        if(cnt>m){str.erase(m);cnt=m;}
    }
    cout<<str.substr(0,k);
    return 0;
}
*/
//7
/*
#include<iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==b){
            if(a==0){
                cout<<"false"<<endl;
            }else{
                cout<<"true"<<endl;
            }

        }else if(a>b){
            cout<<"false"<<endl;
        }else{
            if((b-a)%3==0){
                cout<<"true"<<endl;
            }else{
            cout<<"false"<<endl;
            }
        }
    }
    return 0;
}
*/
//9
#include<iostream>
using namespace std;
int r,s,n;
int dp[310][310];
int main()
{
    int cnt=0;
    cin>>r>>s>>n;
    for(int i=0; i<=s; i++)dp[0][i]=1;
    for(int i=0; i<=r; i++)dp[i][0]=1;
    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=s; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=r; j++)
        {
            cin>>dp[i][j];
            if(dp[i][j]*dp[i-1][j]>=n && dp[i][j]*dp[i-1][j]==0)
            {
                cnt++;
                cout<<"$##################"<<cnt<<endl;
                dp[i][j]=0;
            }

            if(dp[i][j]*dp[i][j-1]>=n && dp[i][j]*dp[i][j-1]==0)
            {
                cnt++;
                cout<<"$##################"<<cnt<<endl;
                dp[i][j]=0;
            }

            dp[i][j]=max(dp[i][j]*dp[i-1][j],dp[i][j]*dp[i][j-1]);
        }
    }
    for(int i=0; i<=r; i++)
    {
        for(int j=0; j<=s; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<cnt;
    return 0;
}
