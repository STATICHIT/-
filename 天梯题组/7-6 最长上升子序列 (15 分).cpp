#include <bits/stdc++.h>
using namespace std;
int a[20001],f[20001];
int n;
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    f[1]=1;
    for (int i=2; i<=n; i++)
    {
        f[i]=1;//����ֵ Ҫ�Ǹ�����ǰ���κ�һ������С ��ô�����������������Ϊ1
        for (int j=1; j<i; j++)
        {
            if(a[i]>a[j]&&f[i]<f[j]+1) //��Ϊ��λ�õ������ܱ�ǰ��ĺü��������� ������Ҫ�ҳ�����Ǹ�Ȼ��+1
            {
                f[i]=f[j]+1;
            }
        }
    }
    int max_=1;
    for (int i=1; i<=n; i++)//�ҳ����ֵ
    {
        if(max_<f[i])
        {
            max_=f[i];
        }
    }
    cout<<max_;
    return 0;
}
