/*
//�޷��ﵽ���������Not arrive����
//������һ���ܴ������������������������˵�������������û�����¹���˵�����ܵ���
#include<bits/stdc++.h>
using namespace std;
const int inf=99999999;
int sx,sy,ex,ey,minn;
int mapp[10000][10000];//���鲻Ҫ��̫����Ŷ��Ȼ���ڴ泬�޵�
int h,l,m;
void dfs(int x,int y,int step)
{
    int next[4][2]= {{0,1},{1,0},{0,-1},{-1,0}};

    if(x==ex&&y==ey)//�������յ�
    {
        //������Сֵ
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
        cin>>h>>l;//��ͼ����
        cin>>m;
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            mapp[a][b]=1;//�ϰ�����Ϊ1
        }
        cin>>sx>>sy>>ex>>ey;//��������յ�����
        minn=inf;//�������·��Ϊ���ɴﵽ�Ĵ�����
        mapp[sx][sy]=2;//�ȱ�����Ϊ·���еĵ�
        dfs(sx,sy,0);//����㿪ʼ����
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

//���ʹ��kmp
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
        s+=s;//��Ϊ�����ǻ�״������Ҫ�ټ��ϱ���ģ��ɻ�
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
