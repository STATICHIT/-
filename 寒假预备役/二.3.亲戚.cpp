#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int f[10000];
int findd(int x)//������
{
    if(f[x]==x)//�Լ������Լ��İְ�
        return x;
    else
        return f[x]=findd(f[x]);//˳����ڲ����İְ�ֱ�Ӹĳ��ϴ�
}
void combine(int x,int y)
{
    if(findd(x)!=findd(y))
        f[findd(x)]=findd(y);
}
int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)//��ʼ��f����
        f[i]=i;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        combine(a,b);
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(findd(a) == findd(b))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
