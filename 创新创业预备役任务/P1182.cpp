#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,mid,ans,a[1000001];

bool check(int x)
{
    int tot=0,cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(tot+a[i]<=x)
            tot+=a[i];
        else
        {
            tot=a[i];//��һ��
            cnt++;//����+1
        }
    }
    return cnt>=m;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        l=max(l,a[i]);//��С���ֵ����С�����Ԫ��
        r+=a[i];
    }

    while(l<=r)//��С��������ܴ����ܺ�
    {
        mid=(l+r)>>1;
        if(check(mid))//��ֶ��ˣ�˵��ֵ̫С�ˣ����������������ֵ��һ���
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<l;
    return 0;
}
