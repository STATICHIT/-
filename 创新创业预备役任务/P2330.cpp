#include<bits/stdc++.h>
using namespace std;
int n,m,f[100001],ans;
struct node
{
    int x,y,v;
} a[100001];
int getf(int i)
{
    if(i==f[i])return i;
    else return f[i]=getf(f[i]);
}
bool cmd(node a,node b)//�Զ����������
{
    return a.v<b.v;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)f[i]=i;//��ʼ��
    for(int i=1; i<=m; i++)cin>>a[i].x>>a[i].y>>a[i].v;//¼������
    int cnt=0;//��ȷ�ϱߵļ�����
    sort(a+1,a+m+1,cmd);
    for(int i=0; i<=m; i++)//��³˹����
    {
        int aa=getf(a[i].x);
        int bb=getf(a[i].y);
        if(aa!=bb)//������ͨ����������
        {
            ans=a[i].v;//���·�ֵ����������·�ķ�ֵ
            f[aa]=bb;
            cnt++;//�ӱ�
        }
        if(cnt==n-1)//�����ﵽn-1��ʱ˵����������С������
            break;
    }
    cout<<n-1<<" "<<ans;
    return 0;
}
