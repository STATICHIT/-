//��������
#include<bits/stdc++.h>
using namespace std;
long long n,i,j,start,l,s=1;
bool prime(int n)//�ж��Ƿ�������
{
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main()
{
    cin>>n;
    if(prime(n))//�������������ֱ�����1�͸���
        cout<<"1"<<endl<<n<<endl;
    else
    {
        for(i=2; i<=sqrt(n); i++)//n�����Ӳ��ᳬ��sqrt��n��
        {
            s=1;
            for(j=i; s*j<=n; j++)//��i��ͷ����������
            {
                s=s*j;//���ϼ���������
                if(n%s==0&&j-i+1>l)//���������ڳ���l���������Ӷ�Ϊn�����ӣ����������ӵĻ����Ա�n�������ſ��Ը���i��l
                {
                    start=i;//�����������ӿ�ʼ��
                    l=j-i+1;//������������ӳ���
                }
            }
        }
        //����׶�
        cout<<l<<endl;
        for(i=start; i<start+l; i++)
        {
            cout<<i;
            if(i!=start+l-1)//����������һ��������Ҫ��һ��*
                cout<<"*";
        }
    }
    return 0;
}




