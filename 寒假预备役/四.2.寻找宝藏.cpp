#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int road[10001];
int v[101][101];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>road[i];
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>x;
            v[i][j]=x;
        }
    /*
    //����ڽӾ�������������
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    //Floyd�㷨
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(v[i][j]>v[i][k]+v[k][j])
                   v[i][j]=v[i][k]+v[k][j];
    int dan=0;//Σ��ֵ
    for(int i=1;i<m;i++)//ע�������mŶ��Ҫд��n�ˣ�
    {
        dan+=v[road[i]][road[i+1]];
    }
    cout<<dan;
    return 0;
}
