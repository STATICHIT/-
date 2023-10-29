#include<bits/stdc++.h>
using namespace std;
int n,x,y,t;
int a[1010][1010];
queue<int> nx,ny;
int nextt[8][8]= {{-1,0},{1,0},{0,-1},{0,1},{1,-1},{-1,1},{-1,-1},{1,1}};
bool judge(int xx,int yy)
{
    //在地图内
    if(xx>=1&&yy>=1&&xx<=n&&yy<=n)
    {
        if(a[xx][yy]>=1)
            return true;
    }
    return false;
}

void bfs()
{
    while(!nx.empty())
    {
        int x1=nx.front();
        int y1=ny.front();
        nx.pop();
        ny.pop();

        if( x1==n||y1==1 )
        {
            cout<<"No"<<endl;
            return ;
        }
        for(int i=0; i<=7; i++)
        {
            int x2=x1+nextt[i][0];
            int y2=y1+nextt[i][1];
            {
                if(judge(x2,y2))
                {
                    nx.push(x2);
                    ny.push(y2);
                    a[x2][y2]=0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return;
}

//策略：遍历路障
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int o=2*n-2;
        for(int i=1; i<=o; i++)
        {
            cin>>x>>y;
            if(x+y-2>i)
            {
                a[x][y]=1;//标记
                if(x==1||y==n)
                {
                    nx.push(x);
                    ny.push(y);
                }
            }
        }
        bfs();
        memset(a,0,sizeof(a));
    }
    return 0;
}
