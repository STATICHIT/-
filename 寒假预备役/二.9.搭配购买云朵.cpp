//��������һ�����鼯��0/1����������
#include<bits/stdc++.h>
using namespace std;
int n,m,w;//n���ƶ���Ŀ��m����������w��Ǯ��������������
int f[100000];//��������
int dp[100000];
int v[100000],d[100000];//v:�۸񣨼���Ʒ������d����ֵ
int findd(int x)//������
{
    if(f[x]==x)
        return f[x];
    else
        return f[x]=findd(f[x]);
}
void hb(int x,int y)
{
    if(findd(x)!=findd(y))
        f[findd(x)]=findd(y);
}
int main()
{
    cin>>n>>m>>w;
    //��ʼ�����鼯������ÿ���ƶ�ļ۸�ͼ�ֵ
    for(int i=1;i<=n;i++)
        {
            f[i]=i;
            cin>>v[i]>>d[i];
        }

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        hb(a,b);
    }
    for(int i=1;i<=n;i++)//���ϼ۸�&��ֵ�ϲ�
    {
        if(findd(i)!=i)///����ܹؼ�
        {
            v[findd(i)]+=v[i];
            v[i]=0;//�Ѹ��ƶ�ļ۸�ӵ������ڼ����ϴ����棬ԭ���ľ�����
            d[findd(i)]+=d[i];
            d[i]=0;//ͬ��
        }
    }

    //0/1����
    for(int i=1;i<=n;i++)
    {
        for(int j=w;j>=1;j--)//��������
        {
            if(j>=v[i])
                dp[j]=max(dp[j],dp[j-v[i]]+d[i]);
        }
    }
    cout<<dp[w];
    return 0;
}
