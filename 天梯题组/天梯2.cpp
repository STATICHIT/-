/*
//无法达到，则输出“Not arrive”。
//先设置一个很大的数，如果搜索后还是这个数，说明这个步数根本没被更新过，说明不能到达
#include<bits/stdc++.h>
using namespace std;
const int inf=99999999;
int sx,sy,ex,ey,minn;
int mapp[10000][10000];//数组不要开太大了哦不然会内存超限的
int h,l,m;
void dfs(int x,int y,int step)
{
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

    if(x==ex&&y==ey)//到达了终点
    {
        //更新最小值
        if(step<minn)
            minn=step;
        return;
    }
    for(int k=0; k<4; k++)
    {
        int tx=x+next[k][0];
        int ty=y+next[k][1];
        if(tx<0||tx>=h||ty<0||ty>=l)
            continue;
        if(mapp[tx][ty]==0)
        {
            mapp[tx][ty]=2;
            dfs(tx,ty,step+1);
            mapp[tx][ty]=0;
        }
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>h>>l;//地图行列
        cin>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            mapp[a][b]=1;//障碍处标为1
        }
        cin>>sx>>sy>>ex>>ey;//输入起点终点坐标
        minn=inf;//先设最短路径为不可达到的大数字
        mapp[sx][sy]=2;//先标记起点为路径中的点
        dfs(sx,sy,0);//从起点开始搜索
        if(minn!=inf)
            cout<<minn;
        else
            cout<<"Not arrive";
        if(n!=0)cout<<endl;
        memset(mapp,0,sizeof(mapp));
    }
    return 0;
}
*/

//多次使用kmp
/*
#include<bits/stdc++.h>
using namespace std;
#define M 1100000
int nextval[M];
int next_[M];
int l1,l2;
void get_next(string s,string t)
{
    int i=0,k=-1;
    next_[0]=-1;
    while(i<l2)
    {
        if(k == -1 || t[i] == t[k])
        {
            k++;
            i++;
            nextval[i]=k;
            if(t[i] != t[k])
                next_[i]=k;
            else
                next_[i]=next_[k];
        }
        else
            k=next_[k];
    }
}
int index_KMP(string s,string t)
{
    int i = 0,j = 0;
    get_next(s,t);
    while(i < l1)
    {
        if(j == -1||s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
            j=next_[j];
        if(j==l2)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s,t;
        cin>>s>>t;
        s+=s;//因为病毒是环状的所以要再加上本身模拟成环
        //cout<<s<<t;
        l1=s.size();
        l2=t.size();
        //cout<<l1<<"   "<<l2;
        if(index_KMP(s,t)==1)cout<<"Yes";
        if(index_KMP(s,t)==0)cout<<"No";
        if(n!=0)cout<<endl;
    }
    return 0;
}
*/
