#include<bits/stdc++.h>
using namespace std;
int n,m,o,k[100010];
map<long long,int> a,b;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>o;
        k[i]=o;//��¼����1�ı��
        a[o]=1;//��¼������
    }
    for(int i=0;i<m;i++)
    {
     cin>>o;
     if(a[o]==1)//�����ڹ�
            b[o]=1;//��Ƕ��δ���
    }
    for(int i=0;i<n;i++){
           if(b[k[i]]==1)//���δ����߰�����һ˳�����
            cout<<k[i]<<" ";
    }
    return 0;
}
