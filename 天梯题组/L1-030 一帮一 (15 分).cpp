/*
����һ��char���͵��������������֣�һ��int����
�������������Ա�1��ʾ���ԣ�0��ʾŮ�ԣ�������
���ֵ���������߱���������������Ա�ͬ������
����������������ҽ���������˱��һ�£�
�����Ҫ����һ��������һ����С�����飬������
ʼ��δ0�����������Ϊ1��ֱ�����������е�����Ϊ1
*/

#include<bits/stdc++.h>
using namespace std;

char name[55][10];
int s[55],n,book[55];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>s[i]>>name[i];

    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(book[i]==0&&book[j]==0&&s[i]!=s[j])
            {
                book[i]=1;book[j]=1;
                cout<<name[i]<<" "<<name[j]<<endl;
            }
        }
    }
    return 0;
}

