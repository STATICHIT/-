#include<bits/stdc++.h>
using namespace std;
const int inf=999999999;
int f[210][210],vis[210],t[210];//��ά������ͼ����ǡ�ʱ��
int n,m,kk;
int u,v,w;
int main()
{
    cin>>n>>m;
    //��ʼ����ͼ
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=inf;
    //��ʱ�䣬�ı�����λ��ֵ
    for(int i=0; i<n; i++)
    {
        cin>>t[i];//���ؽ�ʱ��
        f[i][i]=0;//˳�㶨���Լ����Լ��ľ���Ϊ0
    }
    //��·��
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        f[u][v]=w;
        f[v][u]=w;//˫��
    }
    cin>>kk;//ѯ�ʴ���
    while(kk--)
    {
        cin>>u>>v>>w;
        for(int k=0; k<n; k++)
        {
            if(t[k]<=w&&!vis[k])//����õ��ڸ�ʱ���Ѿ��޺�����δ�����õ�
            {
                vis[k]=1;//���
                for(int i=0; i<n; i++) //��������
                {
                    for(int j=0; j<n; j++)
                    {
                        if(f[i][j]>f[i][k]+f[k][j])
                            f[i][j]=f[i][k]+f[k][j];
                    }
                }
            }
        }
        if(t[u]<=w&&t[v]<=w&&f[u][v]<inf)cout<<f[u][v]<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
