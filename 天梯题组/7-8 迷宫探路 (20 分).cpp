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
