#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int lnum;//δƥ����������
int ans;//�ڵ���
int main()
{
    cin>>t;
    while(t--)
    {
        lnum=0;ans=0;//һ��Ҫ�ǵö������������Ҫ���㣡��
        cin>>n>>m;//nΪ���Ŵ�����
        char s[n+1];
        cin>>s;//��������
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')//�����ż�����
                lnum++;
            else if(lnum!=0)//����ƥ����������
            {
                lnum--;
                ans++;
            }
        }
        if(ans>=m)//ʹ������m��������Ϊƥ�����Ŵ�
            cout<<1;
        else
            cout<<0;
        if(t!=0)
            cout<<endl;
        }
    return 0;
}
